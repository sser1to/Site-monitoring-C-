#pragma once

namespace WatchufEyeProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			// Создаем и запускаем таймер на 60 секунд для обновления listBox1
			timer = gcnew System::Windows::Forms::Timer();
			timer->Interval = 60000;
			timer->Tick += gcnew EventHandler(this, &MyForm::timer_Tick);
			timer->Start();

			this->WindowState = FormWindowState::Maximized;

			System::Drawing::Text::PrivateFontCollection^ private_fonts = 
				gcnew System::Drawing::Text::PrivateFontCollection();
			private_fonts->AddFontFile("Jura.ttf");
			System::Drawing::Font^ myFont1 = 
				gcnew System::Drawing::Font(private_fonts->Families[0], 16);
			System::Drawing::Font^ myFont2 = 
				gcnew System::Drawing::Font(private_fonts->Families[0], 24);
			System::Drawing::Font^ myFont3 = 
				gcnew System::Drawing::Font(private_fonts->Families[0], 14);
			System::Drawing::Font^ myFont4 = 
				gcnew System::Drawing::Font(private_fonts->Families[0], 10);
			this->button1->Font = myFont1;
			this->button2->Font = myFont1;
			this->button3->Font = myFont1;
			this->button5->Font = myFont4;
			this->listBox1->Font = myFont1;
			this->label1->Font = myFont1;
			this->label2->Font = myFont3;
			this->label3->Font = myFont3;
			this->label4->Font = myFont1;
			this->label5->Font = myFont1;
			this->label6->Font = myFont1;
			this->label7->Font = myFont1;
			this->label8->Font = myFont1;
			this->label9->Font = myFont1;
			this->textBox1->Font = myFont4;
			this->textBox2->Font = myFont4;
			this->textBox3->Font = myFont4;

			// Обновление listBox1 
			button1_Click(nullptr, nullptr);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;

	private:
		System::Windows::Forms::Timer^ timer; // Переменная для таймера

		// Остальные методы и переменные вашего класса MyForm...

		// Обработчик события Tick таймера
		void timer_Tick(Object^ sender, EventArgs^ e) 
		{
			button1_Click(sender, e);
		}


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources =
				(gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			//	
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(141, 32);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(200, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress_1);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Location = System::Drawing::Point(1729, 32);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(162, 59);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Обновить";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(12, 271);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(1880, 732);
			this->listBox1->TabIndex = 3;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Location = System::Drawing::Point(1561, 32);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(162, 59);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Удалить";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->Location = System::Drawing::Point(370, 32);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(162, 59);
			this->button3->TabIndex = 5;
			this->button3->Text = L"+ Добавить";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(141, 71);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(200, 20);
			this->textBox2->TabIndex = 6;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pictureBox1
			// 
			this->pictureBox1->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.ErrorImage")));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(80, 71);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(72)));
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1920, 99);
			this->panel1->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(118, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"WATCHFUL EYE";
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->button5);
			this->panel2->Controls->Add(this->textBox3);
			this->panel2->Controls->Add(this->button4);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->textBox2);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Controls->Add(this->button3);
			this->panel2->Location = System::Drawing::Point(0, 98);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1920, 122);
			this->panel2->TabIndex = 9;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->Location = System::Drawing::Point(1289, 62);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(226, 30);
			this->button5->TabIndex = 13;
			this->button5->Text = L"Сбросить";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(1289, 32);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(199, 20);
			this->textBox3->TabIndex = 12;
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->Location = System::Drawing::Point(1492, 31);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(24, 24);
			this->button4->TabIndex = 11;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(32, 62);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Адрес:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(32, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Название:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 234);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(57, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Название";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(296, 234);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(70, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Адрес сайта";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(970, 234);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(75, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Защита (SSL)";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(681, 234);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(73, 13);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Доступность";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(1352, 234);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(32, 13);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Пинг";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(1637, 234);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(40, 13);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Uptime";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->listBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"WatchfulEye";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: 
		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	private: 
		System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox1_KeyPress_1(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
};
}
