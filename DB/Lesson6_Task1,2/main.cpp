#include <iostream>
#include <string>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <Windows.h>

class Book;
class Sale;
class Stock;

class Publisher
{
public:
	std::string name = "";
	Wt::Dbo::collection<Wt::Dbo::ptr<Book>> books;

	template<typename T>
	void persist(T& a)
	{
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher");
	}
};

class Book
{
public:
	std::string title = "";
	Wt::Dbo::ptr<Publisher> publisher;
	Wt::Dbo::collection < Wt::Dbo::ptr<Stock>> stocks;

	template<typename T>
	void persist(T& a)
	{
		Wt::Dbo::field(a, title, "title");
		Wt::Dbo::belongsTo(a, publisher, "publisher");
		Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "book");
	}
};

class Shop
{
public:
	std::string name = "";
	Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

	template<typename T>
	void persist(T& a)
	{
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "shop");
	}
};

class Stock
{
public:
	Wt::Dbo::ptr<Book> book;
	Wt::Dbo::ptr<Shop> shop;
	int count = 0;
	Wt::Dbo::collection<Wt::Dbo::ptr<Sale>> sales;

	template<typename T>
	void persist(T& a)
	{
		Wt::Dbo::belongsTo(a, book, "book");
		Wt::Dbo::belongsTo(a, shop, "shop");
		Wt::Dbo::field(a, count, "count");
		Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "stock");
	}
};

class Sale
{
public:
	int price = 0;
	std::string date_sale;
	Wt::Dbo::ptr<Stock> stock;
	int count = 0;

	template<typename T>
	void persist(T& a)
	{
		Wt::Dbo::field(a, price, "price");
		Wt::Dbo::field(a, date_sale, "date_sale");
		Wt::Dbo::belongsTo(a, stock, "stock");
		Wt::Dbo::field(a, count, "count");
	}
};

int main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru_RU.UTF-8");

	try
	{
		std::string connectionString =
			"host=localhost "
			"port=5432 "
			"dbname=DB_Lesson6 "
			"user=postgres "
			"password=grsjb2eLAwf";

		auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(connectionString);
		Wt::Dbo::Session session;
		session.setConnection(std::move(postgres));
		session.mapClass<Publisher>("publisher");
		session.mapClass<Book>("book");
		session.mapClass<Stock>("stock");
		session.mapClass<Shop>("shop");
		session.mapClass<Sale>("sale");
		session.createTables();

		Wt::Dbo::Transaction transaction1(session);
		std::unique_ptr<Publisher> publisher1(new Publisher);
		std::unique_ptr<Publisher> publisher2(new Publisher);

		publisher1->name = "Diamond Publishing";
		publisher2->name = "Brilliant Publishing";

		Wt::Dbo::ptr<Publisher> publisherPtr1 = session.add(std::move(publisher1));
		Wt::Dbo::ptr<Publisher> publisherPtr2 = session.add(std::move(publisher2));

		std::unique_ptr<Book> book1(new Book);
		std::unique_ptr<Book> book2(new Book);
		std::unique_ptr<Book> book3(new Book);
		std::unique_ptr<Book> book4(new Book);

		book1->title = "Mist";
		book2->title = "Rise";
		book3->title = "Sundown";
		book4->title = "Manhunt";

		Wt::Dbo::ptr<Book> bookPtr1 = session.add(std::move(book1));
		Wt::Dbo::ptr<Book> bookPtr2 = session.add(std::move(book2));
		Wt::Dbo::ptr<Book> bookPtr3 = session.add(std::move(book3));
		Wt::Dbo::ptr<Book> bookPtr4 = session.add(std::move(book4));

		publisherPtr1.modify()->books.insert(bookPtr1);
		publisherPtr1.modify()->books.insert(bookPtr2);
		publisherPtr2.modify()->books.insert(bookPtr3);
		publisherPtr2.modify()->books.insert(bookPtr4);

		std::unique_ptr<Shop> shop1(new Shop);
		std::unique_ptr<Shop> shop2(new Shop);
		std::unique_ptr<Shop> shop3(new Shop);

		shop1->name = "BestSeller";
		shop2->name = "Bookvill";
		shop3->name = "ReadMe";

		Wt::Dbo::ptr<Shop> shopPtr1 = session.add(std::move(shop1));
		Wt::Dbo::ptr<Shop> shopPtr2 = session.add(std::move(shop2));
		Wt::Dbo::ptr<Shop> shopPtr3 = session.add(std::move(shop3));

		std::unique_ptr<Stock> stock1(new Stock);
		std::unique_ptr<Stock> stock2(new Stock);
		std::unique_ptr<Stock> stock3(new Stock);
		std::unique_ptr<Stock> stock4(new Stock);
		std::unique_ptr<Stock> stock5(new Stock);
		std::unique_ptr<Stock> stock6(new Stock);

		stock1->count = 7;
		stock2->count = 7;
		stock3->count = 6;
		stock4->count = 8;
		stock5->count = 13;
		stock6->count = 9;

		Wt::Dbo::ptr<Stock> stockPtr1 = session.add(std::move(stock1));
		Wt::Dbo::ptr<Stock> stockPtr2 = session.add(std::move(stock2));
		Wt::Dbo::ptr<Stock> stockPtr3 = session.add(std::move(stock3));
		Wt::Dbo::ptr<Stock> stockPtr4 = session.add(std::move(stock4));
		Wt::Dbo::ptr<Stock> stockPtr5 = session.add(std::move(stock5));
		Wt::Dbo::ptr<Stock> stockPtr6 = session.add(std::move(stock6));

		bookPtr1.modify()->stocks.insert(stockPtr1);
		bookPtr1.modify()->stocks.insert(stockPtr2);
		bookPtr2.modify()->stocks.insert(stockPtr3);
		bookPtr3.modify()->stocks.insert(stockPtr4);
		bookPtr4.modify()->stocks.insert(stockPtr5);
		bookPtr4.modify()->stocks.insert(stockPtr6);

		shopPtr1.modify()->stocks.insert(stockPtr1);
		shopPtr1.modify()->stocks.insert(stockPtr3);
		shopPtr2.modify()->stocks.insert(stockPtr2);
		shopPtr2.modify()->stocks.insert(stockPtr5);
		shopPtr3.modify()->stocks.insert(stockPtr4);
		shopPtr3.modify()->stocks.insert(stockPtr6);

		std::unique_ptr<Sale> sale1(new Sale);
		std::unique_ptr<Sale> sale2(new Sale);
		std::unique_ptr<Sale> sale3(new Sale);
		std::unique_ptr<Sale> sale4(new Sale);
		std::unique_ptr<Sale> sale5(new Sale);
		std::unique_ptr<Sale> sale6(new Sale);
		std::unique_ptr<Sale> sale7(new Sale);
		std::unique_ptr<Sale> sale8(new Sale);
		std::unique_ptr<Sale> sale9(new Sale);

		sale1->price = 60;
		sale1->date_sale = "10.03.2022";
		sale1->count = 1;
		sale2->price = 58;
		sale2->date_sale = "11.03.2022";
		sale2->count = 2;
		sale3->price = 55;
		sale3->date_sale = "12.03.2022";
		sale3->count = 1;
		sale4->price = 57;
		sale4->date_sale = "13.03.2022";
		sale4->count = 2;
		sale5->price = 63;
		sale5->date_sale = "14.03.2022";
		sale5->count = 1;
		sale6->price = 62;
		sale6->date_sale = "15.03.2022";
		sale6->count = 1;
		sale7->price = 62;
		sale7->date_sale = "16.03.2022";
		sale7->count = 2;
		sale8->price = 62;
		sale8->date_sale = "17.03.2022";
		sale8->count = 1;
		sale9->price = 62;
		sale9->date_sale = "18.03.2022";
		sale9->count = 1;

		Wt::Dbo::ptr<Sale> salePtr1 = session.add(std::move(sale1));
		Wt::Dbo::ptr<Sale> salePtr2 = session.add(std::move(sale2));
		Wt::Dbo::ptr<Sale> salePtr3 = session.add(std::move(sale3));
		Wt::Dbo::ptr<Sale> salePtr4 = session.add(std::move(sale4));
		Wt::Dbo::ptr<Sale> salePtr5 = session.add(std::move(sale5));
		Wt::Dbo::ptr<Sale> salePtr6 = session.add(std::move(sale6));
		Wt::Dbo::ptr<Sale> salePtr7 = session.add(std::move(sale7));
		Wt::Dbo::ptr<Sale> salePtr8 = session.add(std::move(sale8));
		Wt::Dbo::ptr<Sale> salePtr9 = session.add(std::move(sale9));

		stockPtr1.modify()->sales.insert(salePtr1);
		stockPtr1.modify()->sales.insert(salePtr2);
		stockPtr2.modify()->sales.insert(salePtr3);
		stockPtr3.modify()->sales.insert(salePtr4);
		stockPtr4.modify()->sales.insert(salePtr5);
		stockPtr4.modify()->sales.insert(salePtr6);
		stockPtr5.modify()->sales.insert(salePtr7);
		stockPtr5.modify()->sales.insert(salePtr8);
		stockPtr6.modify()->sales.insert(salePtr9);

		transaction1.commit();

		std::string publisherName;
		std::cout << "Введите имя издателя, что бы найти магазины, в которых продаются его книги: ";
		getline(std::cin, publisherName);
		std::set<std::string> result;
		
		Wt::Dbo::Transaction transaction2(session);
		Wt::Dbo::ptr<Publisher> pub = session.find<Publisher>().where("name=?").bind(publisherName);

		if (pub)
		{
			std::cout << "Книги этого издателя продаются в следующих магазинах:" << std::endl;
			typedef Wt::Dbo::collection<Wt::Dbo::ptr<Book>> Books;
			Books books = session.find<Book>().where("publisher_id = ?").bind(pub.id());
			for (const auto& book : books)
			{
				typedef Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> Stocks;
				Stocks stocks = session.find<Stock>().where("book_id = ?").bind(book.id());
				for (const auto& stock : stocks)
				{
					Wt::Dbo::ptr<Shop> sh = session.find<Shop>().where("id = ?").bind(stock->shop);
					result.insert(sh->name);
				}
			}
			for (const auto& e : result)
			{
				std::cout << e << std::endl;
			}
		}
		else
		{
			std::cout << "Издателя с таким имненем нет в базе.";
		}
		
	}
	catch (Wt::Dbo::Exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}