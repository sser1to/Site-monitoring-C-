#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Net;
using namespace System::Net::NetworkInformation;
using namespace System::IO;
using namespace System::Collections::Generic;

/// <summary>
/// Запуск окна MyForm
/// </summary>
[STAThread]
void main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    WatchufEyeProject::MyForm form;
    Application::Run(% form);
}

namespace WatchufEyeProject
{
    void MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) 
    {
        listBox1->Items->Clear();

        // Считывание информации о сайтах с sites.txt
        array<String^>^ lines = File::ReadAllLines("sites.txt");

        // Добавление информации по каждому сайту в listBox1
        for each (String ^ line in lines) 
        {
            array<String^>^ parts = line->Split(' ');
            String^ siteName = parts[0];
            String^ siteUrl = parts[1];

            // Создание объекта для запроса
            HttpWebRequest^ request = dynamic_cast<HttpWebRequest^>(WebRequest::Create(siteUrl));

            // Получение ответа от сервера
            HttpWebResponse^ response = nullptr;
            try 
            {
                response = dynamic_cast<HttpWebResponse^>(request->GetResponse());
            }
            catch (WebException^ ex) 
            {
                MessageBox::Show("Ошибка при запросе к сайту " + siteName + ": " + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                continue;
            }

            // Получение информации о сайте
            bool sslActivated = (response->SupportsHeaders && response->Headers->Get("Strict-Transport-Security") != nullptr); // Активирована ли SSL защита

            // Закрытие соединения
            response->Close();

            // Пинг сайта
            Ping^ pingSender = gcnew Ping();
            Uri^ uri = gcnew Uri(siteUrl);
            String^ host = uri->Host;
            PingReply^ reply = pingSender->Send(host);
            String^ pingInfo = reply->Status == IPStatus::Success ? reply->RoundtripTime.ToString() + " ms" : "Недоступен";

            // Генерация случайного значения Uprate
            Random^ rnd = gcnew Random();
            int uprate = rnd->Next(75, 100);

            // Формирование строки с информацией о сайте
            String^ siteInfo = siteName->PadRight(50) + "\t" +
                siteUrl->PadRight(50) + "\t" +
                (reply->Status == IPStatus::Success ? "Работает" : "Недоступен") + "\t\t\t" +
                (sslActivated ? "Активирована" : "Не активирована") + "\t\t\t" +
                pingInfo->PadRight(50) + "\t" +
                uprate + "%";

            // Добавление информации о сайте
            listBox1->Items->Add(siteInfo);
        }
    }

    void MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e) 
    {
        if (listBox1->SelectedItem == nullptr) 
        {
            MessageBox::Show("Выберите сайт для удаления!", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        // Удаление выбранного элемента
        int selectedIndex = listBox1->SelectedIndex;
        listBox1->Items->RemoveAt(selectedIndex);

        array<String^>^ lines = File::ReadAllLines("sites.txt");

        // Создание нового списка строк без удаленной строки
        List<String^>^ updatedLines = gcnew List<String^>();
        for (int i = 0; i < lines->Length; i++) 
        {
            if (i != selectedIndex) 
            {
                updatedLines->Add(lines[i]);
            }
        }

        // Перезапись sites.txt с обновленным списком строк
        File::WriteAllLines("sites.txt", updatedLines->ToArray());

        MessageBox::Show("Сайт успешно удален!", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);

        // Обновление listBox1 
        button1_Click(sender, e);
    }

    void MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ siteName = textBox1->Text;
        String^ siteUrl = textBox2->Text;

        // Проверка на пустые значение в полях
        if (siteName->Trim() == "" || siteUrl->Trim() == "") {
            MessageBox::Show("Введите название сайта и ссылку на сайт!", 
                "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        // Проверка на наличие пробелов в поле для названия сайта
        if (siteName->Contains(" ")) {
            MessageBox::Show("Название сайта не должно содержать пробелы!", 
                "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        // Проверка на правильность формата ссылки
        if (!siteUrl->StartsWith("http://") && !siteUrl->StartsWith("https://")) {
            MessageBox::Show("Неправильный формат ссылки! Пожалуйста, введите ссылку в формате http://адрес или https://адрес.", 
                "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        // Проверка на то, чтобы введенное название не повторялось
        String^ filePath = "sites.txt";
        if (File::ReadAllText(filePath)->Contains(siteName)) {
            MessageBox::Show("Имя сайта уже используется, введите другое имя!", 
                "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        // Запрос к сайту
        try 
        {
            // Создаем объект для запроса
            HttpWebRequest^ request = dynamic_cast<HttpWebRequest^>(WebRequest::Create(siteUrl));

            // Получаем ответ от сервера
            HttpWebResponse^ response = dynamic_cast<HttpWebResponse^>(request->GetResponse());

            // Проверяем, что код состояния HTTP равен 200 (Успешный ответ)
            if (response->StatusCode != HttpStatusCode::OK) 
            {
                MessageBox::Show("Сайт недоступен или не существует", 
                    "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                response->Close();
                return;
            }

            // Закрытие соединения
            response->Close();
        }
        catch (Exception^ ex) 
        {
            MessageBox::Show("Ошибка при проверке доступности сайта: " + ex->Message, 
                "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Добавление новой записи в sites.txt
        StreamWriter^ sw = File::AppendText(filePath);
        sw->WriteLine(siteName + " " + siteUrl);
        sw->Close();

        textBox1->Text = "";
        textBox2->Text = "";

        MessageBox::Show("Сайт успешно добавлен!", 
            "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);

        // Обновление listBox1
        button1_Click(sender, e);
    }

    void MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e) 
    {
        
        // Проверка на пустое значение в поле
        if (textBox3->Text->Trim() == "") 
        {
            MessageBox::Show("Вы не ввели значение!", 
                "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        listBox1->Items->Clear();

        // Считывание текста из textBox3
        String^ filter = textBox3->Text->Trim()->ToLower();

        // Считывание информации о сайтах из файла
        array<String^>^ lines = File::ReadAllLines("sites.txt");

        // Добавление информации по каждому сайту в listBox1,
        // название которого соотвествует введенному значению в поиске
        for each (String ^ line in lines) 
        {
            array<String^>^ parts = line->Split(' ');
            String^ siteName = parts[0]->ToLower();

            // Проверка на то, соответствует ли название значению в поиске
            if (siteName->StartsWith(filter)) 
            {
                String^ siteUrl = parts[1]; // Ссылка на сайт

                // Создание объекта для запроса
                HttpWebRequest^ request = dynamic_cast<HttpWebRequest^>(WebRequest::Create(siteUrl));

                // Получение ответа от сервера
                HttpWebResponse^ response = nullptr;
                try 
                {
                    response = dynamic_cast<HttpWebResponse^>(request->GetResponse());
                }
                catch (WebException^ ex) 
                {
                    MessageBox::Show("Ошибка при запросе к сайту " + siteName + ": " + ex->Message, 
                        "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    continue;
                }

                // Получение информации о сайте
                bool sslActivated = (response->SupportsHeaders && 
                    response->Headers->Get("Strict-Transport-Security") != nullptr);

                // Закрываем соединение
                response->Close();

                // Пинг сайта
                Ping^ pingSender = gcnew Ping();
                Uri^ uri = gcnew Uri(siteUrl);
                String^ host = uri->Host;
                PingReply^ reply = pingSender->Send(host);
                String^ pingInfo = reply->Status == IPStatus::Success ? reply->RoundtripTime.ToString() 
                    + " ms" : "Недоступен";

                // Генерация случайного значения Uprate
                Random^ rnd = gcnew Random();
                int uprate = rnd->Next(50, 100);

                // Формирование строки с информацией о сайте
                String^ siteInfo = siteName->PadRight(50) + "\t" +
                    siteUrl->PadRight(50) + "\t" +
                    (reply->Status == IPStatus::Success ? "Работает" : "Недоступен") + "\t\t\t" +
                    (sslActivated ? "Активирована" : "Не активирована") + "\t\t\t" +
                    pingInfo->PadRight(50) + "\t" +
                    uprate + "%";

                listBox1->Items->Add(siteInfo);
            }
        }
    }

    void MyForm::button5_Click(System::Object^ sender, System::EventArgs^ e) 
    {
        textBox3->Text = "";

        // Обновление listBox1
        button1_Click(sender, e);      
    }

    void MyForm::textBox1_KeyPress_1(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
    {
        // Запрет на ввод определенных символов
        if (e->KeyChar == '.' || e->KeyChar == ',' || e->KeyChar == '\\' || e->KeyChar == '/' ||
            e->KeyChar == '@' || e->KeyChar == '_' || e->KeyChar == '-' || e->KeyChar == '+' ||
            e->KeyChar == '=' || e->KeyChar == '"' || e->KeyChar == '\'' || e->KeyChar == ':' ||
            e->KeyChar == ';' || e->KeyChar == '$' || e->KeyChar == '%' || e->KeyChar == '^' ||
            e->KeyChar == '&' || e->KeyChar == '?' || e->KeyChar == '!' || e->KeyChar == '*' ||
            e->KeyChar == '#' || e->KeyChar == '№' || e->KeyChar == ' ' || e->KeyChar == '`'
            || e->KeyChar == '(' || e->KeyChar == ')' || e->KeyChar == '[' || e->KeyChar == ']'
            || e->KeyChar == '{' || e->KeyChar == '}' || e->KeyChar == '|') {
            e->Handled = true;
        }
        // Разрешение обработки нажатия клавиши Backspace
        else if (e->KeyChar == '\b') {}

        // Ограничение в 5 символов
        else if (textBox1->Text->Length >= 5) 
        {
            e->Handled = true;
        }
    }
}
