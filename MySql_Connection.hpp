const char* hostname    = "localhost";
const char* username    = "root";
const char* password    = "";
const char* database    = "quiz";
unsigned int port       = 3306;
const char* unixsocket  = NULL;
unsigned long clientflag = 0;




MYSQL* connectdatabase(){
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, hostname, username, password, database, port, unixsocket, clientflag);
    if(conn){
        cout<<"Connected to database "<<endl;
        return conn;
    }
    else{
        cout<<"Failed to connect to database"<<endl;
        return conn;
    }
}

insertion(MYSQL* conn,string IDdb,string Namedb,string Marksdb,string Totaldb){
    int qstate = 0;
    stringstream  ss;

    ss << "INSERT INTO quiz (ID, Name, Marks, Total) VALUES ('"+IDdb+"','"+Namedb+"', '"+Marksdb+"', '"+Totaldb+"')";
    string query = ss.str();
    const char* q = query.c_str();
    qstate = mysql_query(conn, q);
    if(qstate == 0){
        cout<<"\nRecord inserted...~~~ \n";
    }
    else{
        cout<<"\nFailed to insert...~~~ \n";
    }

}

display(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES* res;
    if(conn){
        int qstate = mysql_query(conn, "SELECT * FROM quiz");
        if(!qstate){
            cout <<"\tID\tName\tMarks\tOut off" << endl;
            res = mysql_store_result(conn);
            int count = mysql_num_fields(res);
            while(row = mysql_fetch_row(res)){
                    for(int i=0;i<count;i++){
                        cout<<"\t"<<row[i];
                    }
                    cout<<endl;

            }
        }

    }
    else{
        cout<<"Failed to fetch ";


    }




}
deletedb(MYSQL* conn)
{
    string username;
    stringstream ss;
    cout<<"Enter Username of record ";
    cin>>username;

    ss  << "DELETE FROM quiz WHERE Name = '"+username+"' ";
    string query = ss.str();
    const char* q = query.c_str();
    int qstate = mysql_query(conn, q);
    if(qstate == 0){
        cout<<"~~~~~Record deleted...~~~ \n";
    }
    else{
        cout<<"~~~~~failed to delete...~~~ \n";
    }


}
