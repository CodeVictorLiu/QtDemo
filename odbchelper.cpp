#include "odbchelper.h"

OdbcHelper::OdbcHelper()
{

    this->db=QSqlDatabase::addDatabase("QODBC");
    QString conn="Driver={PostgreSQL UNICODE(x64)};Server=127.0.0.1;Port=5432;Uid=postgres;Pwd=postgres;Database=0108";
    this->db.setDatabaseName(conn);
    if(!this->db.open())
    {
        QMessageBox::critical(0,QString ("odbc error"),QString("??open db error").arg(this->db.lastError().text()));
        return ;

    }
}

void OdbcHelper::getPointId(){
    QSqlQuery *query=new QSqlQuery(db);
    QString sql="select id from mycollardata order by id";

    query->prepare(sql);
//    query->bindValue(0,1);

    query->exec();
    while(query->next()){
        qDebug()<<query->value(0).toInt();
    }
    query->~QSqlQuery();
}
