#pragma once

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <string>

#include "SF5_MFC_AI_POPDlg.h"

using namespace std;

class MySQL_Connector
{
public:
    MySQL_Connector() : driver(nullptr), con(nullptr), pstmt(nullptr), result(nullptr) {}

    ~MySQL_Connector() {
        if (result) { delete result; result = nullptr; }
        if (pstmt) { delete pstmt; pstmt = nullptr; }
        if (con) { delete con; con = nullptr; }
    }

    bool connect(string server, string username, string password, string database);
    bool login(string id, string pw);
    bool getData(int i);
    CString getMessage();


    bool getID();
    bool getFrom();

private:
    sql::Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;
    sql::ResultSet* result; // ���� �����庰 result ���� �߰�
};
