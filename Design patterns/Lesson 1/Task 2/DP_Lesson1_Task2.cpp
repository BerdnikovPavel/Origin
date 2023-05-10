#include <iostream>
#include <vector>
#include <map>

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

    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept
    {
        for (auto& element : columns)
        {
            column_names.push_back(element);
        }
        return *this;
    }

    SqlSelectQueryBuilder& AddFrom(std::string table_name)
    {
        this->table_name = table_name;
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(std::string column_name, std::string value)
    {
        conditions[column_name] = value;
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept
    {
        for (auto iter{ kv.begin() }; iter != kv.end(); ++iter)
        {
            conditions[iter->first] = iter->second;
        }
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

        if (!conditions.empty())
        {
            query += "WHERE ";
            std::map<std::string, std::string>::iterator iter = conditions.begin();
            for (int i = 0; iter != conditions.end(); iter++, i++)
            {
                if (i == conditions.size() - 1)
                {
                    query += iter->first + "=" + iter->second + ";";
                }
                else
                {
                    query += iter->first + "=" + iter->second + " AND ";
                }
            }
        }
        return query;
    }

private:
    std::string table_name;
    std::vector<std::string> column_names;
    std::map<std::string, std::string> conditions;
};

int main()
{
    std::map<std::string, std::string> conditions
    {
        {"id", "42"}, {"name", "John"}
    };

    std::vector<std::string> columns;
    columns.push_back("name");
    columns.push_back("surname");

    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("phone").AddColumn("GPA");
    query_builder.AddColumns(columns);
    query_builder.AddWhere(conditions);
    query_builder.AddFrom("students");
    query_builder.AddWhere("gender", "man").AddWhere("class", "8");

    std::cout << query_builder.BuildQuery() << std::endl;

    return 0;
}
