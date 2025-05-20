/*! @file Interface.cpp
	@brief Implementation of the Interface 
	@author Arturo Pardini

	Details.
*/ 


#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include "CFunction.h"
#include "Polynomial.h"
#include "Exponential.h"
#include "Interface.h"

void Menu(){
    vector<Function*> f;
    int userchoice=0;
    int i, j, k,p;
    while(1){
        PrintMenu();
        cin>>userchoice;
        switch(userchoice)
        {
        case 0:
            exit(-1);
        case 1:
            Showlist(f);
            break;
        case 2:
        
            i=0;
            i=InsertFun(f);
            if(i==1){
                cout<<"Function inserted!"<<endl;
            }
            else{
                cout<<"Function not inserted :("<<endl;
            }
            break;
        

        case 3:
            j=0;
            j=DeleteFun(f);
            if(i==1){
                cout<<"Function deleted!"<<endl;
            }
            else{
                cout<<"Function not deleted :("<<endl;
            }

            break;
        case 4:
            k=0;
            k=DeleteAll(f);
            if(i==1){
                cout<<"All functions deleted!"<<endl;
            }
            else{
                cout<<"All functions not deleted :("<<endl;
            }

            break;
        case 5:
            p=0;
            p=SelectFun(f);
            if(i==1){
                cout<<"Done!"<<endl;
            }
            else{
                cout<<"not done :("<<endl;
            }

            break;
        default:
            exit(-1);    
        }
    }
}
void PrintMenu(){
    cout<<"---Function menu:---"<<endl;
    cout<<"Type:"<<endl;
    cout<<"0 - Esci dal menù"<<endl;
    cout<<"1 - Visualizza la lista delle funzioni"<<endl;
    cout<<"2 - Inserisci una funzione"<<endl;
    cout<<"3 - Elimina una funzione"<<endl;
    cout<<"4 - Elimina tutte le funzioni"<<endl;
    cout<<"5 - Seleziona una funzione"<<endl;
}
void Showlist(vector<Function*> f){
    int i = f.size();
    cout << "Youf Functions:" << endl;
    for(int j=0;i<=(i-1);j++){
        cout << (j+1) << ")";
        (f.at(j))->Dump();
        cout << endl;
    }
}
int InsertFun(vector<Function*> f){
    cout << "You can insert an Exponential function or a Polynomial function. " << endl;
    cout << "Type 0 to insert an Exponential, 1 to insert a Polynomial, others to quit: "<< endl;
    int a;
    cin >> a;
    Exponential e;
    Polynomial p;
    switch(a)
    {
    case 0 :
        double b;
		double k;
		double c;
        cout<<"Insert the coefficents (b,k,c) of your Exponential:"<<endl;
        cin>>b;
        cin>>k;
        cin>>c;
        e.SetExponential(b,k,c);
        break;
    case 1 :
        int deg;
        double* param;
        cout <<"What is the degree of your Polynomial?" << endl;
        cin>>deg;
        param = new double [deg+1];
        cout <<"Insert the coefficents of the Polynomial" << endl;
        for(int j=0;j<=deg+1;j++){
            cin>>param[j];
        }
        p.SetPolynomial(param,deg+1);
        break;
    default:
        exit(-1);
    }
    int choice=0;
    if(a==0){
        cout <<"If you want to insert this Exponential type 1 :"<<endl;
        e.Dump();
        cin>>choice;
        if(choice==1){
            f.push_back(&e);
            return choice;
        }
        else
            return 0;

    }
    else if(a==1){
        cout <<"If you want to insert this Polynomial type 1 :"<<endl;
        p.Dump();
        cin>>choice;
        if(choice==1){
            f.push_back(&p);
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
     
}
int DeleteFun(vector<Function*> f){
    int i = f.size();
    int choice=0;
    int confirm=0;
    while(1){
    cout << "Insert the ID of the function you want to erase(-1 to exit):"<<endl;
    cin>>choice;
    if(choice > 0 && choice <= i){
        cout <<"If you want to erase this Function type 1 :"<<endl;
        (f.at(choice-1))->Dump();
        cin>>confirm;
        if(confirm==1){
            f.erase (f.begin()+(choice-1));
            return 1;
        }
    }
    else if(choice==-1)
        break;
    else
        cout <<"not valid ID" << endl;
    }
    return 0;
}
int DeleteAll(vector<Function*> f){
    cout << "If you want to delete all print 1:"<< endl;
    int a=0;
    cin>>a;
    if(a==1){
        f.clear();
        return 1;
    }
    return 0;
}
int SelectFun(vector<Function*> f){
    int i = f.size();
    int choice=0;
    double x;
    while(1){
    cout << "Insert the ID of the function you want to valutate(-1 to exit):"<<endl;
    cin>>choice;
    if(choice > 0 && choice <= i){
        (f.at(choice-1))->Dump();
        cout << "Insert the value of x:"<<endl;
        cin>>x;
        (f.at(choice-1))->GetValue(x);
        cout<<endl;
    }
    else if(choice==-1)
        break;
    else
        cout <<"not valid ID" << endl;
    }
    return 0;
}