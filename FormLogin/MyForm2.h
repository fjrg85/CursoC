#pragma once
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
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(String^ mensaje, String^ pwd)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
			//lblWelcome->Text = mensaje;

			//std::string nombreStr = msclr::interop::marshal_as<std::string>("Archivo.txt");
			std::ifstream file("Archivo.txt");/////
			std::string contenidoArchivo((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

			String^ contenidoArchivoNet = msclr::interop::marshal_as<System::String^>(contenidoArchivo);
			if (contenidoArchivoNet->Equals(pwd)) {
				lblWelcome->Text = mensaje;
			}
			else
			{
				lblWelcome->Text = "Clave Incorrecta";
			}

			//lblWelcome->Text = contenidoArchivoNet;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnClose;
	protected:
	private: System::Windows::Forms::Label^ lblWelcome;

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
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->lblWelcome = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(180, 252);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(75, 23);
			this->btnClose->TabIndex = 0;
			this->btnClose->Text = L"&Cerrar";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &MyForm2::btnClose_Click);
			// 
			// lblWelcome
			// 
			this->lblWelcome->AutoSize = true;
			this->lblWelcome->Location = System::Drawing::Point(135, 151);
			this->lblWelcome->Name = L"lblWelcome";
			this->lblWelcome->Size = System::Drawing::Size(60, 13);
			this->lblWelcome->TabIndex = 1;
			this->lblWelcome->Text = L"Bienvenida";
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(590, 405);
			this->Controls->Add(this->lblWelcome);
			this->Controls->Add(this->btnClose);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
