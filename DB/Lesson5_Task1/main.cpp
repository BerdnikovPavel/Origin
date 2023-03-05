#include <iostream>
#include <pqxx/pqxx>
#include <windows.h>

class Data_management
{

private:
	pqxx::connection& c1;
public:
	Data_management(pqxx::connection& c) : c1(c){}

	void create_table()
	{
		pqxx::work tx(c1);
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

	void add_client(std::string first_name, std::string last_name, std::string email)
	{
		pqxx::work tx(c1);
		tx.exec("INSERT INTO clients(first_name, last_name, email) "
			"VALUES('" + tx.esc(first_name) + "', '" + tx.esc(last_name) + "', '" + tx.esc(email) + "')");
		tx.commit();
	}

	void add_telephone_number(std::string client_id, std::string telephone_number)
	{
		pqxx::work tx(c1);
		tx.exec("INSERT INTO clients_telephone(client_id, telephone_number) "
			"VALUES('"+ tx.esc(client_id) +"', '" + tx.esc(telephone_number) + "')");
		tx.commit();
	}

	void change_data(std::string client_id, std::string column, std::string new_info)
	{
		pqxx::work tx(c1);
		tx.exec("UPDATE clients SET "+ column +"='" + new_info + "' WHERE id='" + client_id + "'");
		tx.commit();
	}

	void delete_telephone(std::string client_id)
	{
		pqxx::work tx(c1);
		tx.exec("DELETE FROM clients_telephone WHERE client_id='" + client_id + "'");
		tx.commit();
	}

	void delete_client(std::string client_id)
	{
		pqxx::work tx(c1);
		tx.exec("DELETE FROM clients WHERE id='" + client_id + "'");
		tx.commit();
	}

	void search_client(std::string x)
	{
		pqxx::work tx(c1);
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

	void search_by_telephone(std::string t_number)
	{
		pqxx::work tx(c1);

		for (auto [first_name, last_name, telephone_number] : tx.query<std::string, std::string, std::string>(
			"SELECT first_name, last_name, telephone_number FROM clients_telephone ct "
			"JOIN clients c on ct.client_id = c.id WHERE ct.telephone_number = '" + t_number + "'"))
		{
			if (t_number == telephone_number)
			{
				std::cout << "Данный телефон пренадлежит: " << first_name << " " << last_name << std::endl;
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

		Data_management dm(c);
		dm.create_table();
		dm.add_client("Павел", "Иванов", "PI@mail.ru");
		dm.add_client("Андрей", "Смирнов", "AS@mail.ru");
		dm.add_client("Алекснадр", "Сидоров", "AS@mail.ru");
		dm.add_telephone_number("2", "83459830595");
		dm.add_telephone_number("1", "11095849687");
		dm.change_data("1", "first_name", "Иван");
		dm.delete_client("3");
		dm.search_client("Смирнов");
		dm.search_by_telephone("83459830595");
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