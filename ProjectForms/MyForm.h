#pragma once
#include "MyForm2.h"

namespace ProjectForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnSumar;
	protected:
	private: System::Windows::Forms::TextBox^ txtNumero1;
	private: System::Windows::Forms::TextBox^ txtNumero2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnSumar = (gcnew System::Windows::Forms::Button());
			this->txtNumero1 = (gcnew System::Windows::Forms::TextBox());
			this->txtNumero2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnSumar
			// 
			this->btnSumar->Location = System::Drawing::Point(202, 185);
			this->btnSumar->Name = L"btnSumar";
			this->btnSumar->Size = System::Drawing::Size(75, 23);
			this->btnSumar->TabIndex = 0;
			this->btnSumar->Text = L"Sumar";
			this->btnSumar->UseVisualStyleBackColor = true;
			this->btnSumar->Click += gcnew System::EventHandler(this, &MyForm::btnSumar_Click);
			// 
			// txtNumero1
			// 
			this->txtNumero1->Location = System::Drawing::Point(84, 135);
			this->txtNumero1->Name = L"txtNumero1";
			this->txtNumero1->Size = System::Drawing::Size(100, 20);
			this->txtNumero1->TabIndex = 1;
			// 
			// txtNumero2
			// 
			this->txtNumero2->Location = System::Drawing::Point(293, 135);
			this->txtNumero2->Name = L"txtNumero2";
			this->txtNumero2->Size = System::Drawing::Size(100, 20);
			this->txtNumero2->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(81, 110);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Número 1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(301, 110);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Número 1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(553, 468);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtNumero2);
			this->Controls->Add(this->txtNumero1);
			this->Controls->Add(this->btnSumar);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnSumar_Click(System::Object^ sender, System::EventArgs^ e) {
		int num1, num2, suma;
		try {

			num1 = Convert::ToInt32(txtNumero1->Text);
			num2 = Convert::ToInt32(txtNumero2->Text);
			suma = num1 + num2;
			MessageBox::Show("Suma = " + suma.ToString());


			String^ paraEnviar = "Frutas";
			MyForm2^ main = gcnew MyForm2(paraEnviar);
			main->ShowDialog();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Exception\n" + ex->ToString());
		}
	}
	};
}
