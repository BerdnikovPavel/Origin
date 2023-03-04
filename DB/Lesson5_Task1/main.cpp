#include <iostream>
#include <pqxx/pqxx>
#include <windows.h>

class Data_management
{
public:
	Data_management(){}

	void create_table(pqxx::connection& c)
	{
		pqxx::work tx(c);
		tx.exec("create table if not exists clients ( "
			"id SERIAL primary key, "
			"first_name varchar(60) not null, "
			"last_name varchar(60) not null, "
			"email varchar(60) not null)");
		tx.exec("create table if not exists clients_telephone ( "
			"id serial primary key, "
			"client_id INTEGER not null references clients(id), "
			"telephone_number varchar(20))");
		tx.commit();
	}

	void add_client(pqxx::connection& c, std::string first_name, std::string last_name, std::string email)
	{
		pqxx::work tx(c);
		tx.exec("INSERT INTO clients(first_name, last_name, email) "
			"VALUES('" + tx.esc(first_name) + "', '" + tx.esc(last_name) + "', '" + tx.esc(email) + "')");
		tx.commit();
	}

	void add_telephone_number(pqxx::connection& c, std::string client_id, std::string telephone_number)
	{
		pqxx::work tx(c);
		tx.exec("INSERT INTO clients_telephone(client_id, telephone_number) "
			"VALUES('"+ tx.esc(client_id) +"', '" + tx.esc(telephone_number) + "')");
		tx.commit();
	}

	void change_data(pqxx::connection& c, std::string client_id, std::string column, std::string new_info)
	{
		pqxx::work tx(c);
		tx.exec("UPDATE clients SET "+ column +"='" + new_info + "' WHERE id='" + client_id + "'");
		tx.commit();
	}

	void delete_telephone(pqxx::connection& c, std::string client_id)
	{
		pqxx::work tx(c);
		tx.exec("DELETE FROM clients_telephone WHERE client_id='" + client_id + "'");
		tx.commit();
	}

	void delete_client(pqxx::connection& c, std::string client_id)
	{
		pqxx::work tx(c);
		tx.exec("DELETE FROM clients WHERE id='" + client_id + "'");
		tx.commit();
	}

	void search_client(pqxx::connection& c, std::string x)
	{
		pqxx::work tx(c);
		for (auto [id, first_name, last_name, email] : tx.query<int, std::string, std::string, std::string>(
			"SELECT id, first_name, last_name, email FROM clients"))
		{
			if (x == first_name || x == last_name || x == email)
			{
				std::cout << "id искомого клиента: " << id << std::endl;
			}
		}

		for (auto [client_id, telephone_number] : tx.query<int, std::string>(
			"SELECT client_id, telephone_number FROM clients_telephone"))
		{
			if (x == telephone_number)
			{
				std::cout << "id искомого клиента: " << client_id << std::endl;
			}
		}
	}
};

int main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru_RU.UTF-8");

	try
	{
		pqxx::connection c(
			"host=localhost "
			"port=5432 "
			"dbname=clients "
			"user=postgres "
			"password=grsjb2eLAwf");

		

		Data_management dm;
		dm.create_table(c);
		dm.add_client(c, "Павел", "Иванов", "PI@mail.ru");
		dm.add_client(c, "Андрей", "Смирнов", "AS@mail.ru");
		dm.add_client(c, "Алекснадр", "Сидоров", "AS@mail.ru");
		dm.add_telephone_number(c, "2", "83459830595");
		dm.add_telephone_number(c, "1", "11095849687");
		dm.change_data(c, "1", "first_name", "Иван");
		dm.delete_client(c, "3");
		dm.search_client(c, "Смирнов");
	}
	catch (const pqxx::sql_error& e)
	{
		std::cout << "Error happened" << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown error happened" << std::endl;
	}

	return 0;
}