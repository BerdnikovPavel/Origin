#include <iostream>
#include <vector>

class SqlSelectQueryBuilder
{
public:
    SqlSelectQueryBuilder()
    {

    }

    SqlSelectQueryBuilder& AddColumn(std::string column_name) noexcept
    {
        column_names.push_back(column_name);
        return *this;
    }

    SqlSelectQueryBuilder& AddFrom(std::string table_name)
    {
        this->table_name = table_name;
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(std::string column_name, std::string value)
    {
        where.push_back(std::make_pair(column_name, value));
        return *this;
    }

    std::string BuildQuery() noexcept
    {
        std::string query = "SELECT ";
        if (!column_names.empty())
        {
            std::vector<std::string>::iterator iter = column_names.begin();
            while (iter != column_names.end())
            {
                if (iter == column_names.end() - 1)
                {
                    query += *iter + " ";
                    ++iter;
                }
                else
                {
                    query += *iter + ", ";
                    ++iter;
                }
            }
        }

        query += "FROM " + table_name + " ";

        if (!where.empty())
        {
            query += "WHERE ";
            std::vector< std::pair<std::string, std::string>>::iterator iter = where.begin();
            while (iter != where.end())
            {
                if (iter == where.end() - 1)
                {
                    query += iter->first + "=" + iter->second + ";";
                    ++iter;
                }
                else
                {
                    query += iter->first + "=" + iter->second + " AND ";
                    ++iter;
                }
            }
        }
        return query;
    }

private:
    std::string table_name;
    std::vector<std::string> column_names;
    std::vector<std::pair<std::string, std::string>> where;

};

int main()
{
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");

    std::cout << query_builder.BuildQuery();

    //static_assert(query_builder.BuildQuery(),
        //"SELECT name, phone FROM students WHERE id=42 AND name=John;");
}