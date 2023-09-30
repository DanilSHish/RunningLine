#pragma once

namespace RunningLine {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		int l;
		int a;
		int position;
		int time;
		Color color;
		int max_pos;
		void StartStop(bool);

	public:
		MainForm(void)
		{
			InitializeComponent();
			position = -1;
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ToolStripMenuItem^ îñòàíîâêàToolStripMenuItem;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ çàïóñêToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ïàğàìåòğûToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ îÏğîãğàììåToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ïîìîùüToolStripMenuItem;


	private: System::Windows::Forms::Panel^ panel1;
	private: System::ComponentModel::IContainer^ components;



#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Òğåáóåìûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà — íå èçìåíÿéòå 
		   /// ñîäåğæèìîå ıòîãî ìåòîäà ñ ïîìîùüş ğåäàêòîğà êîäà.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->çàïóñêToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->îñòàíîâêàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->ïàğàìåòğûToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->îÏğîãğàììåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->ïîìîùüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->menuStrip1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				   this->çàïóñêToolStripMenuItem,
					   this->îñòàíîâêàToolStripMenuItem, this->ïàğàìåòğûToolStripMenuItem, this->îÏğîãğàììåToolStripMenuItem, this->ïîìîùüToolStripMenuItem
			   });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(624, 24);
			   this->menuStrip1->TabIndex = 0;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // çàïóñêToolStripMenuItem
			   // 
			   this->çàïóñêToolStripMenuItem->Enabled = false;
			   this->çàïóñêToolStripMenuItem->Name = L"çàïóñêToolStripMenuItem";
			   this->çàïóñêToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			   this->çàïóñêToolStripMenuItem->Text = L"Çàïóñê";
			   this->çàïóñêToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::çàïóñêToolStripMenuItem_Click);
			   // 
			   // îñòàíîâêàToolStripMenuItem
			   // 
			   this->îñòàíîâêàToolStripMenuItem->Name = L"îñòàíîâêàToolStripMenuItem";
			   this->îñòàíîâêàToolStripMenuItem->Size = System::Drawing::Size(77, 20);
			   this->îñòàíîâêàToolStripMenuItem->Text = L"Îñòàíîâêà";
			   this->îñòàíîâêàToolStripMenuItem->Visible = false;
			   this->îñòàíîâêàToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::îñòàíîâêàToolStripMenuItem_Click);
			   // 
			   // ïàğàìåòğûToolStripMenuItem
			   // 
			   this->ïàğàìåòğûToolStripMenuItem->Name = L"ïàğàìåòğûToolStripMenuItem";
			   this->ïàğàìåòğûToolStripMenuItem->Size = System::Drawing::Size(83, 20);
			   this->ïàğàìåòğûToolStripMenuItem->Text = L"Ïàğàìåòğû";
			   this->ïàğàìåòğûToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ïàğàìåòğûToolStripMenuItem_Click);
			   // 
			   // îÏğîãğàììåToolStripMenuItem
			   // 
			   this->îÏğîãğàììåToolStripMenuItem->Name = L"îÏğîãğàììåToolStripMenuItem";
			   this->îÏğîãğàììåToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			   this->îÏğîãğàììåToolStripMenuItem->Text = L"Î ïğîãğàììå";
			   this->îÏğîãğàììåToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::îÏğîãğàììåToolStripMenuItem_Click);
			   // 
			   // ïîìîùüToolStripMenuItem
			   // 
			   this->ïîìîùüToolStripMenuItem->Name = L"ïîìîùüToolStripMenuItem";
			   this->ïîìîùüToolStripMenuItem->Size = System::Drawing::Size(68, 20);
			   this->ïîìîùüToolStripMenuItem->Text = L"Ïîìîùü";
			   this->ïîìîùüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ïîìîùüToolStripMenuItem_Click);
			   // 
			   // panel1
			   // 
			   this->panel1->BackColor = System::Drawing::Color::White;
			   this->panel1->Location = System::Drawing::Point(12, 27);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(600, 402);
			   this->panel1->TabIndex = 2;
			   this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::panel1_Paint);
			   // 
			   // timer1
			   // 
			   this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			   // 
			   // MainForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(624, 441);
			   this->Controls->Add(this->panel1);
			   this->Controls->Add(this->menuStrip1);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->MainMenuStrip = this->menuStrip1;
			   this->MaximizeBox = false;
			   this->Name = L"MainForm";
			   this->Text = L"Òğåóãîëüíèêè";
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
	private: System::Void ïàğàìåòğûToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void çàïóñêToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void îÏğîãğàììåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ïîìîùüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void îñòàíîâêàToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e);
	};
}
