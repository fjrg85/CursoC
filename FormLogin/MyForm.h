#pragma once
#include "MyForm2.h"
#include <fstream>
#include "msclr/marshal_cppstd.h"

namespace FormLogin {

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
	private: System::Windows::Forms::TextBox^ txtUser;
	protected:
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::Button^ btnAccept;

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
			this->txtUser = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->btnAccept = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtUser
			// 
			this->txtUser->Location = System::Drawing::Point(108, 92);
			this->txtUser->Name = L"txtUser";
			this->txtUser->Size = System::Drawing::Size(100, 20);
			this->txtUser->TabIndex = 0;
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(292, 92);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->PasswordChar = '*';
			this->txtPassword->Size = System::Drawing::Size(100, 20);
			this->txtPassword->TabIndex = 1;
			// 
			// btnAccept
			// 
			this->btnAccept->Location = System::Drawing::Point(203, 164);
			this->btnAccept->Name = L"btnAccept";
			this->btnAccept->Size = System::Drawing::Size(75, 23);
			this->btnAccept->TabIndex = 2;
			this->btnAccept->Text = L"&Aceptar";
			this->btnAccept->UseVisualStyleBackColor = true;
			this->btnAccept->Click += gcnew System::EventHandler(this, &MyForm::btnAccept_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(528, 283);
			this->Controls->Add(this->btnAccept);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->txtUser);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnAccept_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ user;
		String^ pwd;
		try {

			user = txtUser->Text;
			pwd = txtPassword->Text;
			
			String^ paraEnviar = "Bienvenido " + user;// +" \nTu clave es: " + pwd;
			MyForm2^ main = gcnew MyForm2(paraEnviar, pwd);
			main->ShowDialog();
			/*this->Visible=false;
			main->Show();
			this->Visible = true;*/

			std::string paraEnviarStr = msclr::interop::marshal_as<std::string>(paraEnviar);
			std::string nombreStr = msclr::interop::marshal_as<std::string>(txtUser->Text);
			std::ofstream file(nombreStr + ".txt");

			if (file.is_open()) {
				file << paraEnviarStr;
				file.close();
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Exception\n" + ex->ToString());
		}
	}
	};
}
