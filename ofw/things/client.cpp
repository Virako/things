#include <cstdlib>
#include <iostream>
#include "mongo/client/dbclient.h"

using namespace std;

void run() {
  mongo::DBClientConnection conn;
  conn.connect("localhost");
}

void insert_user(mongo::DBClientConnection & conn, const char *mail, const char *pass)
{
    mongo::BSONObjBuilder obj;
    obj.append("mail", mail);
    obj.append("pass", pass);
    conn.insert("ofw.users", obj.obj());
}

void insert_bug(mongo::DBClientConnection & conn, const char *name, int height, int width, int type)
{
    mongo::BSONObjBuilder obj;
    obj.append("name", name);
    obj.append("height", height);
    obj.append("width", width);
    obj.append("type", type);
    conn.insert("ofw.bugs", obj.obj());
}

void insert_npc(mongo::DBClientConnection & conn, const char *name, int height, int width)
{
    mongo::BSONObjBuilder obj;
    obj.append("name", name);
    obj.append("height", height);
    obj.append("width", width);
    conn.insert("ofw.npcs", obj.obj());
}

void insert_player(mongo::DBClientConnection & conn, const char *name, int height, int width, int type)
{
    mongo::BSONObjBuilder obj;
    obj.append("name", name);
    obj.append("height", height);
    obj.append("width", width);
    obj.append("type", type);
    conn.insert("ofw.players", obj.obj());
}

void insert_item(mongo::DBClientConnection & conn, const char *name, int type, int power, char *values)
{
    mongo::BSONObjBuilder obj;
    obj.append("name", name);
    obj.append("type", type);
    obj.append("power", power);
    obj.append("values", values);
    conn.insert("ofw.items", obj.obj());
}

void insert_skill(mongo::DBClientConnection & conn, const char *name, int type, char *values)
{
    mongo::BSONObjBuilder obj;
    obj.append("name", name);
    obj.append("type", type);
    obj.append("values", values);
    conn.insert("ofw.skills", obj.obj());
}

void insert_mision(mongo::DBClientConnection & conn, const char *name, char *objetives)
{
    mongo::BSONObjBuilder obj;
    obj.append("name", name);
    obj.append("objetives", objetives);
    conn.insert("ofw.misions", obj.obj());
}

void insert_village(mongo::DBClientConnection & conn, const char *name, char *values)
{
    mongo::BSONObjBuilder obj;
    obj.append("name", name);
    obj.append("values", values);
    conn.insert("ofw.villages", obj.obj());
}

int main(void) {

    //const char *port = "27017";
    mongo::DBClientConnection conn;
    string errmsg;
    if ( ! conn.connect( string( "localhost" ) /*+ port*/ , errmsg ) ) {
        cout << "couldn't connect : " << errmsg << endl;
        throw -11;
    }

    //{
    //    // clean up old data from any previous tests
    //    mongo::BSONObjBuilder query;
    //    conn.remove( "test.people" , query.obj() );
    //}

    insert_user(conn, "a", "a@ofw.es");
    insert_user(conn, "b", "b@ofw.es");
    insert_user(conn, "c", "c@ofw.es");
    insert_user(conn, "d", "d@ofw.es");
    insert_user(conn, "e", "e@ofw.es");
    insert_user(conn, "f", "f@ofw.es");
    insert_user(conn, "g", "g@ofw.es");
    insert_user(conn, "h", "h@ofw.es");
    insert_user(conn, "i", "i@ofw.es");
    insert_user(conn, "j", "j@ofw.es");

    //insert( conn, "a", 1 );
    //insert( conn, "a", 2 );
    //insert( conn, "a", 3 );
    //insert( conn, "a", 4 );
    //insert( conn, "a", 5 );
    //insert( conn, "a", 6 );
    //insert( conn, "a", 7 );
    //insert( conn, "a", 8 );
    //insert( conn, "a", 9 );
    //insert( conn, "a", 10 );

    //{
    //    mongo::BSONObj query = BSON( "num" << BSON( "$nin" << BSON_ARRAY(1 << 5 << 10) ) );
    //    cout << query << endl;

    //    auto_ptr<mongo::DBClientCursor> cursor = conn.query( "test.people" , query );
    //    cout << "using cursor" << endl;
    //    while ( cursor->more() ) {
    //        mongo::BSONObj obj = cursor->next();
    //        cout << "\t" << obj.jsonString() << endl;
    //    }
    //}
}
