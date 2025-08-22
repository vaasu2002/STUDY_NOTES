# Builder Design Pattern

Gives us mechanism to construct complex objects steup by step. If classes has many variables, constructors becomes bulky and looks ugly. Most of the time, most of the parameters are unused.


### Fluent Build

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class QueryBuilder; // forward declare

class Query {
    friend class QueryBuilder;

    std::string m_database;
    std::vector<std::string> m_columns;
    std::string m_table;
    std::string m_condition;
    int m_limitCount = -1;
    
    // private constructor
    Query() = default; 
public:
    std::string str() const {
        std::ostringstream ss;
        ss << "SELECT ";

        if (m_columns.empty()) {
            ss << "*";
        } else {
            for (size_t i = 0; i < m_columns.size(); i++) {
                ss << m_columns[i];
                if (i < m_columns.size() - 1) ss << ", ";
            }
        }

        ss << " FROM " << m_table;

        if (!m_condition.empty()) {
            ss << " WHERE " << m_condition;
        }

        if (m_limitCount >= 0) {
            ss << " LIMIT " << m_limitCount;
        }

        return ss.str();
    }

    static QueryBuilder create();
};

class QueryBuilder {
    Query query;

public:
    QueryBuilder() = default;

    QueryBuilder& select(const std::vector<std::string>& columns) {
        query.m_columns = columns;
        return *this;
    }

    QueryBuilder& from(const std::string& table) {
        query.m_table = table;
        return *this;
    }

    QueryBuilder& where(const std::string& condition) {
        query.m_condition = condition;
        return *this;
    }

    QueryBuilder& limit(int n) {
        query.m_limitCount = n;
        return *this;
    }

    Query build() {
        return query;
    }
};

QueryBuilder Query::create() {
    return QueryBuilder();
}

int main() {
    Query q = Query::create()
                  .select({"id", "name"})
                  .from("users")
                  .where("age > 18")
                  .limit(10)
                  .build();

    std::cout << q.str() << std::endl;
}

```
