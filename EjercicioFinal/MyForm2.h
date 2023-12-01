#pragma once
#include <mysql.h>
#include <Windows.h>
#include "msclr/marshal_cppstd.h"// Incluimos la libreriapara convertir de std::string a String^
MYSQL* conectar;  // La variable tipo MYSQL para establecer el resultado de la conexión

namespace MiSqlFORM {

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
		MyForm2(String^ nombre, String^ autor, String^ precio)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			txtAutor->Text = nombre;
			txtTitulo->Text = autor;
			txtPrecio->Text = precio;
		}
	private:
		bool conectamos() {
			conectar = mysql_init(0); // 
			int puerto = 3366;
			conectar = mysql_real_connect(conectar, "localhost", "fjrg85", "04012001", "cursocpp", puerto, NULL, 0);

			if (!conectar) {
				// No se pudo establecer la conexión
				return false;
			}
			return true;
		}
		bool queries(const char* q) {
			if (mysql_query(conectar, q)) {
				// La consulta mysql_query() devuelve 0 en caso de éxito, 
				// cualquier otro número en casod e error
				// Manejar el error según sea necesario
				return false;
			}
		}
		void addcart(std::string titulo, std::string autor, std::string precio) {
			try {
				if (conectamos()) {

					std::string query = "INSERT INTO carrito (nombre, precio) VALUES ('" + titulo + "','" + precio + "')";
					if (!queries(query.c_str())) {
						MessageBox::Show("No se pudo realizar la consulta");
					}					
					mysql_close(conectar);
				}
				else {
					MessageBox::Show("no conectado");
				}
			}
			catch (Exception^ ex) {
				Console::WriteLine("error:" + ex);

			}
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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtTitulo;
	private: System::Windows::Forms::TextBox^ txtPrecio;
	private: System::Windows::Forms::TextBox^ txtAutor;
	private: System::Windows::Forms::Button^ btnAdd;
	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtTitulo = (gcnew System::Windows::Forms::TextBox());
			this->txtPrecio = (gcnew System::Windows::Forms::TextBox());
			this->txtAutor = (gcnew System::Windows::Forms::TextBox());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(56, 61);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Titulo";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(56, 96);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(32, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Autor";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(56, 133);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(37, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Precio";
			// 
			// txtTitulo
			// 
			this->txtTitulo->Location = System::Drawing::Point(112, 61);
			this->txtTitulo->Name = L"txtTitulo";
			this->txtTitulo->ReadOnly = true;
			this->txtTitulo->Size = System::Drawing::Size(223, 20);
			this->txtTitulo->TabIndex = 3;
			// 
			// txtPrecio
			// 
			this->txtPrecio->Location = System::Drawing::Point(112, 130);
			this->txtPrecio->Name = L"txtPrecio";
			this->txtPrecio->ReadOnly = true;
			this->txtPrecio->Size = System::Drawing::Size(100, 20);
			this->txtPrecio->TabIndex = 4;
			// 
			// txtAutor
			// 
			this->txtAutor->Location = System::Drawing::Point(112, 93);
			this->txtAutor->Name = L"txtAutor";
			this->txtAutor->ReadOnly = true;
			this->txtAutor->Size = System::Drawing::Size(223, 20);
			this->txtAutor->TabIndex = 5;
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(137, 181);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 23);
			this->btnAdd->TabIndex = 6;
			this->btnAdd->Text = L"&Agregar";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &MyForm2::btnAdd_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(507, 281);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->txtAutor);
			this->Controls->Add(this->txtPrecio);
			this->Controls->Add(this->txtTitulo);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {

		std::string stitulo = msclr::interop::marshal_as<std::string>(txtTitulo->Text);
		std::string sautor = msclr::interop::marshal_as<std::string>(txtAutor->Text);
		std::string sprecio = msclr::interop::marshal_as<std::string>(txtPrecio->Text);

		addcart(stitulo, sautor, sprecio);
			

	}
};
}
