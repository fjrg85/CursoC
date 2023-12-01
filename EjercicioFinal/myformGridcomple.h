#pragma once
#include <mysql.h>
#include <Windows.h>
#include "msclr/marshal_cppstd.h"// Incluimos la libreria para convertir de std::string a String^
MYSQL* conectar;  // La variable tipo MYSQL para establecer el resultado de la conexión
MYSQL_RES* resultado; // La variable tipo MYSQL para establecer el resultado de la respuesta de una consulta
MYSQL_ROW fila; // Variable MYSQL en la que albergaremos datos de una fila de la respuesta de la consulta.
std::string query;
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
			conectar = mysql_real_connect(conectar, "localhost", "104cubes@gmail.com", "ablaracurcix", "cursocpp", puerto, NULL, 0);

			if (!conectar) {
				// No se pudo establecer la conexión
				return false;
			}
			return true;
		}


		bool getInfo(String^ col, String^ w) {
			String^ wh="";
			if (col && col!="")
			String^ wh = "WHERE " + col + " = '"+w;
			String^ query = "SELECT * FROM usuarios" + wh;
			std::string queryStr = msclr::interop::marshal_as<std::string>(query);
			if (mysql_query(conectar, queryStr.c_str())) {
				// La consulta mysql_query() devuelve 0 en caso de éxito, 
				// cualquier otro número en casod e error
				// Manejar el error según sea necesario
				return false;

			}
			resultado = mysql_store_result(conectar);
			if (!mysql_num_fields(resultado)) {
				return false;
			}
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
	private: System::Windows::Forms::TextBox^ Nombre;
	private: System::Windows::Forms::TextBox^ Password;
	private: System::Windows::Forms::TextBox^ mPassword;
	private: System::Windows::Forms::TextBox^ mNombre;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ insertar;
	private: System::Windows::Forms::Label^ actualizar;
	private: System::Windows::Forms::Label^ emNombre;

	private: System::Windows::Forms::Label^ emPassword;
	private: System::Windows::Forms::DataGridViewButtonColumn^ Eliminar;

	protected:

	protected:

	private:

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			//Declaramos controles
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->Enviar = (gcnew System::Windows::Forms::Button());
			this->Tabla = (gcnew System::Windows::Forms::DataGridView());
			this->Nombre = (gcnew System::Windows::Forms::TextBox());
			this->Password = (gcnew System::Windows::Forms::TextBox());
			this->mPassword = (gcnew System::Windows::Forms::TextBox());
			this->mNombre = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->insertar = (gcnew System::Windows::Forms::Label());
			this->actualizar = (gcnew System::Windows::Forms::Label());
			this->emNombre = (gcnew System::Windows::Forms::Label());
			this->emPassword = (gcnew System::Windows::Forms::Label());
			this->Eliminar = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Tabla))->BeginInit();
			this->SuspendLayout();
			//Control por control 
			// 
			// Enviar
			// 
			this->Enviar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Enviar->Location = System::Drawing::Point(943, 580);
			this->Enviar->Margin = System::Windows::Forms::Padding(4);
			this->Enviar->Name = L"Enviar";
			this->Enviar->Size = System::Drawing::Size(162, 73);
			this->Enviar->TabIndex = 0;
			this->Enviar->Text = L"Enviar";
			this->Enviar->UseVisualStyleBackColor = true;
			this->Enviar->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// Tabla
			// 
			this->Tabla->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->Tabla->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Tabla->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Tabla->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Eliminar });
			this->Tabla->Location = System::Drawing::Point(102, -3);
			this->Tabla->Margin = System::Windows::Forms::Padding(4);
			this->Tabla->Name = L"Tabla";
			this->Tabla->RowHeadersWidth = 82;
			this->Tabla->RowTemplate->Height = 33;
			this->Tabla->Size = System::Drawing::Size(1308, 533);
			this->Tabla->TabIndex = 1;
			this->Tabla->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::Tabla_CellContentClick);
			this->Tabla->CellLeave += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::Tabla_CellContentLeave);
			// 
			// Nombre
			// 
			this->Nombre->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Nombre->Location = System::Drawing::Point(241, 580);
			this->Nombre->Margin = System::Windows::Forms::Padding(4);
			this->Nombre->Name = L"Nombre";
			this->Nombre->Size = System::Drawing::Size(272, 31);
			this->Nombre->TabIndex = 2;
			// 
			// Password
			// 
			this->Password->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Password->Location = System::Drawing::Point(635, 580);
			this->Password->Margin = System::Windows::Forms::Padding(4);
			this->Password->Name = L"Password";
			this->Password->Size = System::Drawing::Size(272, 31);
			this->Password->TabIndex = 3;
			// 
			// mPassword
			// 
			this->mPassword->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->mPassword->Location = System::Drawing::Point(635, 733);
			this->mPassword->Margin = System::Windows::Forms::Padding(4);
			this->mPassword->Name = L"mPassword";
			this->mPassword->Size = System::Drawing::Size(272, 31);
			this->mPassword->TabIndex = 6;
			// 
			// mNombre
			// 
			this->mNombre->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->mNombre->Location = System::Drawing::Point(241, 733);
			this->mNombre->Margin = System::Windows::Forms::Padding(4);
			this->mNombre->Name = L"mNombre";
			this->mNombre->Size = System::Drawing::Size(272, 31);
			this->mNombre->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Location = System::Drawing::Point(943, 733);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(162, 73);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Modificar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// insertar
			// 
			this->insertar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->insertar->AutoSize = true;
			this->insertar->Location = System::Drawing::Point(133, 585);
			this->insertar->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->insertar->Name = L"insertar";
			this->insertar->Size = System::Drawing::Size(84, 25);
			this->insertar->TabIndex = 7;
			this->insertar->Text = L"insertar";
			// 
			// actualizar
			// 
			this->actualizar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->actualizar->AutoSize = true;
			this->actualizar->Location = System::Drawing::Point(127, 639);
			this->actualizar->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->actualizar->Name = L"actualizar";
			this->actualizar->Size = System::Drawing::Size(200, 25);
			this->actualizar->TabIndex = 8;
			this->actualizar->Text = L"Modificar Password";
			// 
			// emNombre
			// 
			this->emNombre->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->emNombre->AutoSize = true;
			this->emNombre->Location = System::Drawing::Point(231, 681);
			this->emNombre->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->emNombre->Name = L"emNombre";
			this->emNombre->Size = System::Drawing::Size(87, 25);
			this->emNombre->TabIndex = 9;
			this->emNombre->Text = L"Nombre";
			// 
			// emPassword
			// 
			this->emPassword->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->emPassword->AutoSize = true;
			this->emPassword->Location = System::Drawing::Point(623, 681);
			this->emPassword->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->emPassword->Name = L"emPassword";
			this->emPassword->Size = System::Drawing::Size(174, 25);
			this->emPassword->TabIndex = 10;
			this->emPassword->Text = L"Nuevo Password";
			// 
			// La columna que se llama eliminar y repite un botón en la primera columna de cada línea
			// 
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Eliminar->DefaultCellStyle = dataGridViewCellStyle1;
			this->Eliminar->HeaderText = L"Eliminar";
			this->Eliminar->MinimumWidth = 10;
			this->Eliminar->Name = L"Eliminar";
			this->Eliminar->Text = L"Eliminar";
			this->Eliminar->Width = 200;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1682, 898);
			this->Controls->Add(this->emPassword);
			this->Controls->Add(this->emNombre);
			this->Controls->Add(this->actualizar);
			this->Controls->Add(this->insertar);
			this->Controls->Add(this->mPassword);
			this->Controls->Add(this->mNombre);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Password);
			this->Controls->Add(this->Nombre);
			this->Controls->Add(this->Tabla);
			this->Controls->Add(this->Enviar);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Tabla))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	String^ celdaAnt; // Variable para recger el valor de la celda del GridView que pinchamos

	// Cuando carga la ventana.
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		if (conectamos()) {

			if (!getInfo("", "")) {
				MessageBox::Show("No se pudo realizar la consulta");
			}
			mysql_close(conectar);
		}
		else {
			MessageBox::Show("No se pudo realizar la conexión a la bbdd");
		}
	};

		   // Insert desde campos de form
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		try {
			if (conectamos()) {

				std::string NombreStr = msclr::interop::marshal_as<std::string>(Nombre->Text);
				std::string PasswordStr = msclr::interop::marshal_as<std::string>(Password->Text);
				

				query = "INSERT INTO usuarios (nombre,password) VALUES ('" + NombreStr + "','" + PasswordStr + "')";
				if (!queries(query.c_str())) {
					MessageBox::Show("El nombre de usuario ya existe");
				}
			
				if (!getInfo("", "")) {
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
		   // Update desde campos de form
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		if (conectamos()) {

			std::string mNombreStr = msclr::interop::marshal_as<std::string>(mNombre->Text);
			std::string mPasswordStr = msclr::interop::marshal_as<std::string>(mPassword->Text);
			if (!getInfo("nombre", mNombre->Text)) {
				MessageBox::Show("El usuario no existe");
			}
			query = "UPDATE usuarios SET password='" + mPasswordStr + "' WHERE nombre='" + mNombreStr + "'";
			if (!queries(query.c_str())) {
				MessageBox::Show("No se pudo realizar la consulta");
			}
			if (!getInfo("","")) {
				MessageBox::Show("No se pudo realizar la consulta");
			}
			mysql_close(conectar);
		}
		else {
			MessageBox::Show("No se pudo realizar la conexión a la bbdd");
		}

	}
		   // Al hacer click en una celda de la tabla
	private: System::Void Tabla_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		
		String^ columnName = dynamic_cast<DataGridView^>(sender)->Columns[e->ColumnIndex + 2]->Name;
		std::string columnaStr = msclr::interop::marshal_as<std::string>(columnName);
		Object^ cellValue = Tabla->Rows[e->RowIndex]->Cells[e->ColumnIndex + 2]->Value;
		std::string celdaStr = msclr::interop::marshal_as<std::string>(cellValue->ToString());

			  // Verificar si se hizo clic en una celda de botón y la columna es la de eliminación
		if (conectamos()) {

			// Si la celda es de la columna "Eliminar" eso se convierte en un botón.
			// los elementos de esa columna son tipo button
			if (e->ColumnIndex == Tabla->Columns["Eliminar"]->Index && e->RowIndex >= 0) // Si la celda es de la columna "Eliminar"

			{
				MessageBox::Show(columnName + "___" + cellValue->ToString());

				// Eliminar la fila correspondiente
				query = "DELETE FROM usuarios WHERE " + columnaStr + "='" + celdaStr + "'";
				if (!queries(query.c_str())) {
					MessageBox::Show("No se pudo realizar la consulta");
				}
				
				if (!getInfo("", "")) {
					MessageBox::Show("No se pudo realizar la consulta");
				}
			}
			// Si no es el de eliminar recogemos su valor.
			else {
			
				Object^ cellValue = Tabla->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value;
				celdaAnt = cellValue->ToString(); // Recogemos el valor de la celda si no es de la columna eliminar
				MessageBox::Show(celdaAnt);
			
			}
			mysql_close(conectar);
		}
	}










		   // Cuando dejamos el foco de una celda... Para modificar la bbdd con 
		   // lo que acabaos de escribir. Habría que detectar si el valor es modificable ne la bbdd.
	private: System::Void Tabla_CellContentLeave(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		
		/*	if (conectamos()) {

			String^ columnName = dynamic_cast<DataGridView^>(sender)->Columns[e->ColumnIndex]->Name;
			std::string columnaStr = msclr::interop::marshal_as<std::string>(columnName);
			Object^ LeavecellValue = Tabla->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value;
			std::string celdaStr = msclr::interop::marshal_as<std::string>(LeavecellValue->ToString());
			if (celdaAnt) {
				String^ celdaAnttoStr = celdaAnt;
				std::string celdaAntStr = msclr::interop::marshal_as<std::string>(celdaAnttoStr);

				query = "UPDATE usuarios SET " + columnaStr + "='" + celdaStr + "' WHERE " + columnaStr + "='" + celdaAntStr + "'";

			}
			else {
				query = "INSERT INTO usuarios (" + columnaStr + ") VALUES ('" + celdaStr + "')";

			}
			if (!queries(query.c_str())) {
				MessageBox::Show("No se pudo realizar la consulta");
			}
			query = "SELECT * FROM usuarios";
			if (!getInfo()) {
				MessageBox::Show("No se pudo realizar la consulta");
			}
			mysql_close(conectar);
		}
		else {
			MessageBox::Show("No se pudo realizar la conexión a la bbdd");
		}
		*/
	}
	};
};
