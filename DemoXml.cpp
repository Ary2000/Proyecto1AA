#include "pugixml.hpp"

#include <iostream>
using namespace std;

int main()
{

    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_file("world.xml");

    pugi::xml_node pais1 = doc.child("svg").child("path");      //check whethert the file is loaded successfully   

    cout << "Load result: " << result.description() <<endl<<endl;  
 
    cout<<" Books Ids :"<<endl<<endl;

    cout<<" Book 1 Id : " << pais1.attribute("id").value() << endl;   //get the value of attribute id of book1

    cout<<" Book 1 Id : " << pais1.attribute("style").set_value("fill:#f20f0f;fill-rule:evenodd") << endl;   //get the value of attribute id of book1



    pugi::xml_node pais2 = pais1.next_sibling();

    cout<<" Book 2 Id : " << pais2.attribute("id").value() << endl;     //get the value of attribute id of book2

  
    
    pugi::xml_node pais3 = pais2.next_sibling();

    cout<<" Book 3 Id : " << pais3.attribute("d").value() << endl;    //get the value of attribute id of book3

    std::cout << "Saving result: " << doc.save_file("mundo.xml") << std::endl;

  
     

}