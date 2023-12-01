#pragma once
#include "MyForm2.h"
#include <mysql.h>
#include <Windows.h>
#include "msclr/marshal_cppstd.h"// Incluimos la libreriapara convertir de std::string a String^
MYSQL* conectar;  // La variable tipo MYSQL para establecer el resultado de la conexión
MYSQL_RES* resultado; // La variable tipo MYSQL para establecer el resultado de la respuesta de una consulta
MYSQL_ROW fila; // Variable MYSQL en la que albergaremos datos de una fila de la respuesta de la consulta.


namespace MiSqlFORM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
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
		bool getInfo() {
			if (mysql_query(conectar, "SELECT * FROM libros")) {
				// La consulta mysql_query() devuelve 0 en caso de éxito, 
				// cualquier otro número en casod e error
				// Manejar el error según sea necesario
				return false;

			}
			resultado = mysql_store_result(conectar);
			// Obtener el resultado
			//
			//Creamos una tabla
			DataTable^ Tabla = gcnew DataTable();

			// Agregar columnas a la tabla
			for (unsigned int i = 0; i < mysql_num_fields(resultado); i++) { // mysql_num_fields();
				Tabla->Columns->Add(gcnew String(mysql_fetch_field_direct(resultado, i)->name));// mysql_fetch_field_direct();

			}
			// Procesar las filas
			while ((fila = mysql_fetch_row(resultado))) {
				DataRow^ dataRow = Tabla->NewRow();
				for (unsigned int i = 0; i < mysql_num_fields(resultado); i++) {
					dataRow[i] = gcnew String(fila[i] ? fila[i] : "NULL");
				}
				Tabla->Rows->Add(dataRow);
			}
			this->Tabla->DataSource = Tabla;
			mysql_free_result(resultado);
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

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Enviar;
	private: System::Windows::Forms::DataGridView^ Tabla;



	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Enviar = (gcnew System::Windows::Forms::Button());
			this->Tabla = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Tabla))->BeginInit();
			this->SuspendLayout();
			// 
			// Enviar
			// 
			this->Enviar->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->Enviar->Location = System::Drawing::Point(440, 251);
			this->Enviar->Margin = System::Windows::Forms::Padding(2);
			this->Enviar->Name = L"Enviar";
			this->Enviar->Size = System::Drawing::Size(74, 37);
			this->Enviar->TabIndex = 0;
			this->Enviar->Text = L"Enviar";
			this->Enviar->UseVisualStyleBackColor = true;
			this->Enviar->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// Tabla
			// 
			this->Tabla->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Tabla->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Tabla->Location = System::Drawing::Point(58, 6);
			this->Tabla->Margin = System::Windows::Forms::Padding(2);
			this->Tabla->Name = L"Tabla";
			this->Tabla->RowHeadersWidth = 82;
			this->Tabla->RowTemplate->Height = 33;
			this->Tabla->Size = System::Drawing::Size(560, 227);
			this->Tabla->TabIndex = 1;
			this->Tabla->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::Tabla_CellClick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(683, 319);
			this->Controls->Add(this->Tabla);
			this->Controls->Add(this->Enviar);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Tabla))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		if (conectamos()) {
			if (!getInfo()) {
				MessageBox::Show("No se pudo realizar la consulta");
			}
			mysql_close(conectar);
		}
		else {
			MessageBox::Show("No se pudo realizar la conexión a la bbdd");
		}
	};

	private: System::Void Tabla_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

		//MessageBox::Show(e->RowIndex.ToString());
		//MessageBox::Show(Tabla->Rows[e->RowIndex]->Cells[1]->Value->ToString());

		String^ titulo = Tabla->Rows[e->RowIndex]->Cells[1]->Value->ToString();
		String^ autor = Tabla->Rows[e->RowIndex]->Cells[2]->Value->ToString();
		String^ precio = Tabla->Rows[e->RowIndex]->Cells[3]->Value->ToString();

		MyForm2^ main = gcnew MyForm2(titulo, autor, precio);
		main->ShowDialog();
	}
	};
}
