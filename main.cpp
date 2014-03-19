#include <QCoreApplication>
#include <QString>
#include <iostream>
#include <fstream>
#include <QDebug>
int main(int argc, char *argv[])
{
    std::ifstream input;
    std::ofstream output;
    double data;

    for (int i=15; i <= 15 ; i++){
        input.open("/home/haskis/OdometriaMoja.csv");
        if(input.is_open()){
            qDebug()<<"Opened";
        }
        else{
            qDebug()<<"Could not";
        }
        output.open("/home/haskis/ODOMETRIAMOJA.csv");
        while(!input.eof()){
            for(int wiersz=0;wiersz<4; wiersz++){
                for(int kolumna=0; kolumna<4;kolumna++){
                    if(input>>data){
                        if(wiersz!=3 && kolumna==3)
                            output<<data<<" ";
                    }
                    else{
                        break;
                    }
                }
            }
            output<<std::endl;
        }
        input.close();
        output.flush();
        output.close();
    }

return 0;
}
