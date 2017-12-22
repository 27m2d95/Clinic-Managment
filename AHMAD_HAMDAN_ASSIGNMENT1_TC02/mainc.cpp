//******************************************************
//NAME : AHMAD HAMDAN
//LECTURE SECTION : TC02
//TUTORIAL SECTION : TT03
//ASSIGNMENT 1
//TEL.NO : 01139007471
//****************************


#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include "windows.h"


using namespace std;

class Patient{
        string name;
        int id;
        int age;
        string address;
        int telephone;
        string visitingdate;
        string diagnosis;
        string prescription;
        double bill;
public:

       string getName(){return name;}
       int getId(){return id;}
       int getAge(){return age;}
       string getAddress(){return address;}
       int getTelephone(){return telephone;}
       string getVisitingDate(){return visitingdate;}
       string getDiagnosis(){return diagnosis;}
       string getPrescription(){return prescription;}
       double getBill(){return bill;}

       void setName(string name){this->name=name;}
       void setId(int id){this->id=id;}
       void setAge(int age){this->age=age;}
       void setAddress(string address){this->address=address;}
       void setTelephone(int telephone){this->telephone=telephone;}
       void setVisitingdate(string visitingdate){this->visitingdate = visitingdate;}
       void setDiagnosis(string diagnosis){this->diagnosis = diagnosis;}
       void setPrescription(string prescription){this->prescription = prescription;}
       void setBill(double bill){this->bill = bill;}

       virtual string getCompname(){}; // virtual function because of polymorphism
       virtual double getMaxamount(){};// virtual function because of polymorphism
       virtual void setCompname(string compname){};// virtual function because of polymorphism
       virtual void setMaxamount(double maxamount){};// virtual function because of polymorphism
       virtual void AddNewpatient(){};

       void NewVisitDetails(){ //function add new visiting details for patients
        cout << "ENTER PATIENT VISIT DATE :" <<endl;
        string visitingdate1;
        cin.ignore();
        cin >> visitingdate1;
        setVisitingdate(visitingdate1);
        cout << "ENTER PATIENT DIAGNOSIS :" <<endl;
        string diagnosis1;
        cin.ignore();
        getline(cin,diagnosis1);
        setDiagnosis(diagnosis1);
        cout << "ENTER PATIENT PRESCIPTION :" <<endl;
        string prescription1;
        cin>>prescription1;
        setPrescription(prescription1);
        cout << "ENTER BILL AMOUNT :" <<endl;
        double bill1;
        cin>>bill1;
        setBill(bill1);
    }
};

class Panel: public Patient{
    string compname;
    double maxamount;
public:

   string getCompname(){return compname;}
   double getMaxamount(){return maxamount;}
   void setCompname(string compname){this->compname = compname;}
   void setMaxamount(double maxamount){this->maxamount = maxamount;}
   void AddNewpatient(){  // add new panel patient
    cout << "ENTER THE PATIENT NAME :" << endl;
    string name1;
    cin.ignore();
    getline(cin,name1);
    setName(name1);
    cout << "ENTER PATIENT NRIC :" <<endl;
    int id1;
    cin>>id1;
    setId(id1);
    cout << "ENTER PATIENT AGE :" <<endl;
    int age1;
    cin >> age1;
    setAge(age1);
    cout << "ENTER PATIENT ADDRESS :" <<endl;
    string address1;
    cin.ignore();
    getline(cin,address1);
    setAddress(address1);
    cout << "ENTER PATIENT TEL.NO :" <<endl;
    int telephone1;
    cin>>telephone1;
    setTelephone(telephone1);
    cout << "ENTER THE COMPANY NAME :" <<endl;
    string compname1;
    cin.ignore();
    getline(cin,compname1);
    compname = compname1;
    cout << "ENTER THE MAX AMOUNT :" <<endl;
    double maxamount1;
    cin >> maxamount1;
    maxamount = maxamount1;
    }


};




class Nonpanel :  public Patient{


public:

    virtual void AddNewpatient(){ //add new non panel patient
     cout << "ENTER THE PATIENT NAME :" << endl;
    string name1;
    cin.ignore();
    getline(cin,name1);
    setName(name1);
    cout << "ENTER PATIENT NRIC :" <<endl;
    int id1;
    cin>>id1;
    setId(id1);
    cout << "ENTER PATIENT AGE :" <<endl;
    int age1;
    cin >> age1;
    setAge(age1);
    cout << "ENTER PATIENT ADDRESS :" <<endl;
    string address1;
    cin.ignore();
    getline(cin,address1);
    setAddress(address1);
    cout << "ENTER PATIENT TEL.NO :" <<endl;
    int telephone1;
    cin>>telephone1;
    setTelephone(telephone1);

    }


};

class Consultation{
    string name;
    string consultdate;
    double fee;
    static double Maxfee; //shared value for all consultation objects

public:
    Consultation(Patient patient[]){

        name= patient->getName();
        consultdate = patient->getVisitingDate();
        fee = patient->getBill();
        setMaxFee();

    }
   string getPatient(){return name;}
   string getConsultdate(){return consultdate;}
   double getFee(){return fee;}
   void setPatient(Patient consult){name=consult.getName();}
   void setConsultdate(Patient consult){consultdate=consult.getVisitingDate();}
   void setFee(Patient consult){fee= consult.getBill();}
   static double getMaxFee(){return Maxfee;}
   void setMaxFee(){Maxfee = Maxfee + fee;}
};
double Consultation :: Maxfee = 0; // static variables cannot be initialized inside the class



void displayPatientDetails(vector<Patient*>& patient){ // function to display the patient details
        for(int i = 0; i < patient.size(); i++){
            cout<<"  --------------------------------------------------------------------------------"<<endl;
            cout << "\t Name : \t" << patient[i]->getName() <<endl;
            cout << "\t NIRC : \t" << patient[i]->getId() <<endl;
            cout << "\t Age  : \t" << patient[i]->getAge() <<endl;
            cout << "\t Address: \t" <<patient[i]->getAddress() <<endl;
            cout << "\t Telephone No : \t" <<patient[i]->getTelephone() << endl;
            cout << "\t Date : \t" <<patient[i]->getVisitingDate() <<endl;
            cout << "\t Diagnosis :\t" << patient[i]->getDiagnosis()<<endl;
            cout << "\t Prescription :\t" <<patient[i]->getPrescription() <<endl;
            cout << "\t Bill :\t" << patient[i]->getBill() <<endl;

            cout<<"  --------------------------------------------------------------------------------"<<endl<<endl;
}
system("pause");
}
void displayConsultation(vector<Consultation>& consult){ //function to display consultation
    for(int i = 0; i < consult.size(); i++){
            cout<<"  -------------------------------------------------------------"<<endl;
            cout<<"   Patient Name \t  Consultation Date \t Consultation Fee "<<endl;
            cout<<"  \t";cout<<consult[i].getPatient();cout<<"\t\t\t";cout<<consult[i].getConsultdate();cout<<"\t\t\t";cout<<consult[i].getFee();cout<<endl;
            }
            cout<<"  -------------------------------------------------------------"<<endl;
            cout<<" TOTAL AMOUNT = "<<Consultation::getMaxFee()<<endl; //getmaxfee referens to consultation class
system("pause");
}

void displayReceipt(vector<Patient*>& patient, int id, string date){ //function to display the reciept
        for(int i = 0; i < patient.size(); i++){
                if(patient[i]->getId() == id && patient[i]->getVisitingDate()==date){ // check the id and date if thy are similar
                        cout<<"---------------------------------------------"<<endl;
                        cout<<"\t NAME :                                    "<<endl;
                        cout<<"\t\t";cout<<  patient[i]->getName()           <<endl;
                        cout<<"---------------------------------------------"<<endl;
                        cout<<"\t DATE :                                    "<<endl;
                        cout<<"\t\t";cout<<  patient[i]->getVisitingDate()   <<endl;
                        cout<<"---------------------------------------------"<<endl;
                        cout<<"\t DIAGNOSIS :                               "<<endl;
                        cout<<"\t\t";cout<<  patient[i]->getDiagnosis()      <<endl;
                        cout<<"---------------------------------------------"<<endl;
                        cout<<"\t PRESCRIPTION :                            "<<endl;
                        cout<<"\t\t";cout<<  patient[i]->getPrescription()   <<endl;
                        cout<<"---------------------------------------------"<<endl;
                        cout<<"\t BILL :                                    "<<endl;
                        cout<<"\t\t";cout<<  patient[i]->getBill()           <<endl;
                        cout<<"---------------------------------------------"<<endl<<endl;

                        system("pause");
                        return;
                }
        }

        cout<<"There is no receipt for this patient ID : "<<id<<endl; // if the condition false
        system("pause");
}

void SavePanelPatient(vector<Patient*>& patient,ofstream& myfile){ //save panel patient details to txt file
  for(int i = 0; i < patient.size(); i++){
    myfile <<patient[i]->getName()<<endl;
    myfile <<patient[i]->getId()<<endl;
    myfile <<patient[i]->getAge();
    myfile <<patient[i]->getAddress()<<endl;
    myfile <<patient[i]->getTelephone();
    myfile <<patient[i]->getDiagnosis()<<endl;
    myfile <<patient[i]->getVisitingDate()<<endl;
    myfile <<patient[i]->getBill();
    myfile <<patient[i]->getCompname()<<endl;
    myfile <<patient[i]->getMaxamount();
    myfile <<patient[i]->getPrescription()<<endl;
  }

  myfile<<"NonPanel"<<endl; // this function contunie saving untill it faces nonpanel
}

void SaveNonPanelPatient(vector<Patient*>& patient,ofstream& myfile){ //save nonpanel patient details to txt file
  for(int i = 0; i < patient.size(); i++){
    myfile <<patient[i]->getName()<<endl;
    myfile <<patient[i]->getId()<<endl;
    myfile <<patient[i]->getAge();
    myfile <<patient[i]->getAddress()<<endl;
    myfile <<patient[i]->getTelephone();
    myfile <<patient[i]->getDiagnosis()<<endl;
    myfile <<patient[i]->getPrescription()<<endl;
     myfile <<patient[i]->getVisitingDate()<<endl;
    myfile <<patient[i]->getBill();
  }
}

void SaveConsultation(vector<Consultation>& consult){ //save consultation details to txt file
    ofstream save;
    save.open("consultaion.txt");
    for(int i = 0; i < consult.size(); i++){
        save <<consult[i].getPatient()<<endl;
        save <<consult[i].getConsultdate()<<endl;
        save <<consult[i].getFee();
    }
    save.close();
}

vector<Patient*> LoadPanelPatient(){ // load panel info from txt

 vector<Patient*> LoadPanel;
 string name;
 int num;
 double fee;
 ifstream load;
 load.open("example.txt");
 getline(load, name);
 while(name != "NonPanel" && !load.eof()){ //condition to contunie loading if it doesnot face nonpanel
    Patient* tempPatient = new Panel();
    tempPatient->setName(name);
    load>>num;
    tempPatient->setId(num);
    load>>num;
    tempPatient->setAge(num);
    getline(load, name);
    tempPatient->setAddress(name);
    load>>num;
    tempPatient->setTelephone(num);
    getline(load, name);
    tempPatient->setDiagnosis(name);
    getline(load, name);
    tempPatient->setVisitingdate(name);
    load>>fee;
    tempPatient->setBill(fee);
    getline(load, name);
    tempPatient->setCompname(name);
    load>>fee;
    tempPatient->setMaxamount(fee);
    getline(load, name);
    tempPatient->setPrescription(name);
    LoadPanel.push_back(tempPatient);
    getline(load, name);
   }
  load.close();
  return LoadPanel;
 }


vector<Patient*> LoadNonPanelPatient(){ //load nonpanel info
 vector<Patient*> LoadNonPanel;
 string name;
 int num;
 double fee;
 ifstream load;
 load.open("example.txt");
 getline(load, name);
 while(name != "NonPanel" && !load.eof()){ //start loading when it face nonpanel
        getline(load, name);}
 while(!load.eof()){
    Patient* tempPatient = new Panel();
    getline(load, name);
    tempPatient->setName(name);
    load>>num;
    tempPatient->setId(num);
    load>>num;
    tempPatient->setAge(num);
    getline(load, name);
    tempPatient->setAddress(name);
    load>>num;
    tempPatient->setTelephone(num);
    getline(load, name);
    tempPatient->setDiagnosis(name);
    getline(load, name);
    tempPatient->setPrescription(name);
    getline(load, name);
    tempPatient->setVisitingdate(name);
    load>>fee;
    tempPatient->setBill(fee);
    LoadNonPanel.push_back(tempPatient);
   }
  load.close();
  return LoadNonPanel;
 }

vector<Consultation> LoadConsultation(){ //load all consultations
    Patient* tempPatient = new Patient();
    vector<Consultation> LoadConsult;
    ifstream load;
    load.open("consultaion.txt");
    string name;
    double fee;
    while(!load.eof()){
        getline(load, name);
        tempPatient->setName(name);
        getline(load, name);
        tempPatient->setVisitingdate(name);
        load>>fee;
        tempPatient->setBill(fee);
        LoadConsult.push_back(tempPatient);
    }
    load.close();
    return LoadConsult;
}



bool oldPatient(vector<Patient*>& patient, int id){ //check condition if the patient is exist or not by id
    for(int i = 0; i < patient.size(); i++){
        if(patient[i]->getId() == id)
        return true;
    }
    return false;
}

Patient* retrievePanel(const vector<Patient*>& patient, int id){ //if the condition above true and the patient exist this function retrives panel patient info
    Patient* CopyPanel = new Panel;
    for(int i = 0; i < patient.size(); i++)
        if(patient[i]->getId() == id)
        {
         CopyPanel->setName(patient[i]->getName());
         CopyPanel->setId(patient[i]->getId());
         CopyPanel->setAge(patient[i]->getAge());
         CopyPanel->setAddress(patient[i]->getAddress());
         CopyPanel->setTelephone(patient[i]->getTelephone());
         CopyPanel->setCompname(patient[i]->getCompname());
         CopyPanel->setMaxamount(patient[i]->getMaxamount());
         return CopyPanel;
        }

}

Patient* retrieveNonPanel(const vector<Patient*>& patient, int id){ //retrive nonpanel
    Patient* CopyNonpanel = new Nonpanel;
    for(int i = 0; i < patient.size(); i++)
        if(patient[i]->getId() == id)
        {
         CopyNonpanel->setName(patient[i]->getName());
         CopyNonpanel->setId(patient[i]->getId());
         CopyNonpanel->setAge(patient[i]->getAge());
         CopyNonpanel->setAddress(patient[i]->getAddress());
         CopyNonpanel->setTelephone(patient[i]->getTelephone());
         return CopyNonpanel;
        }

}

int main()
{
    char chose;
   char chose1;
   string date;
   int NRIC;
   ofstream myfile;


    vector<Patient*> AllPanel = LoadPanelPatient(); //load info
    vector<Patient*> AllNonPanel = LoadNonPanelPatient();
    vector<Consultation> consult = LoadConsultation();

   while(true){
            Patient* patient[2]={new Panel(), new Nonpanel()}; // polymorphism

   system("cls");
   cout << "**************************************************************"<<endl;
   cout << "                WELCOME TO CYBER CLINIC                       "<<endl;
   cout << "**************************************************************"<<endl;
   cout << "Chose below " << endl <<endl;
   cout << "------------------------------ "<<endl;
   cout << "A/a - Add Patient " <<endl;
   cout << "------------------------------ "<<endl;
   cout << "C/c - view consultation" <<endl;
   cout << "------------------------------ "<<endl;
   cout << "R/r - Receipt " <<endl;
   cout << "------------------------------ "<<endl;
   cout << "P/p - Patient Details " <<endl;
   cout << "------------------------------ "<<endl;
   cout << "E/e - Exit" << endl;
   cout << "------------------------------ "<<endl;
   cin >> chose;
   switch(chose){

   case 'A':
   case 'a':
       system("cls");
       cout << "------------------------------ "<<endl;
       cout << "P/p - panel "<<endl;
       cout << "------------------------------ "<<endl;
       cout << "N/n - non panel" << endl;
       cout << "------------------------------ "<<endl;
       cin >> chose1;
       switch (chose1){
       case 'p':
       case 'P':
         cout << "\nENTER PATIENT NRIC :" <<endl;
         cin>>NRIC;
         if(oldPatient(AllPanel,NRIC)){ //call function check by id
            cout<<"Personal details of this patient is recorded\n";
            cout<<"Please Enter Visit Details:\n";
            patient[0] = retrievePanel(AllPanel, NRIC);
            patient[0]->NewVisitDetails();
         }
         else{
          cout<<"New Patient... Please Enter Personal and Visit Details:\n";
          patient[0]->AddNewpatient(); //function call
          patient[0]->NewVisitDetails(); //function call
         }
          AllPanel.push_back(patient[0]);
          consult.push_back(Consultation(patient[0]));
            break;
       case 'N':
       case 'n':
         cout << "\nENTER PATIENT NRIC :" <<endl;
         cin>>NRIC;
         if(oldPatient(AllNonPanel,NRIC)){
            cout<<"Personal details of this patient is recorded\n";
            cout<<"Please Enter Visit Details:\n";
            patient[1] = retrieveNonPanel(AllNonPanel, NRIC);
            patient[1]->NewVisitDetails();
         }
         else{
          cout<<"New Patient... Please Enter Personal and Visit Details:\n";
          patient[1]->AddNewpatient();
          patient[1]->NewVisitDetails();
         }
           AllNonPanel.push_back(patient[1]);
           consult.push_back(Consultation(patient[1]));
            break;
       default:
            cout << "error input" <<endl;
            break;
       }
        break;
   case 'c':
   case 'C':
        displayConsultation(consult);
       break;

   case 'r':
   case 'R':
       system("cls");
       cout << "------------------------------ "<<endl;
       cout << "P/p - panel "<<endl;
       cout << "------------------------------ "<<endl;
       cout << "N/n - non panel" << endl;
       cout << "------------------------------ "<<endl;
       cin >> chose1;
       cout << "ENTER PATIENT NRIC :" <<endl;
       cin>> NRIC;
       cout << "ENTER PATIENT Date :" <<endl;
       cin>> date;
       switch (chose1){
       case 'p':
       case 'P':
         displayReceipt(AllPanel, NRIC, date);
            break;
       case 'N':
       case 'n':
         displayReceipt(AllNonPanel, NRIC, date);
         break;
       default:
            cout << "error input" <<endl;
            break;
       }
       break;
   case 'p':
   case 'P':
       system("cls");
       cout << "------------------------------ "<<endl;
       cout << "P/p - panel "<<endl;
       cout << "------------------------------ "<<endl;
       cout << "N/n - non panel" << endl;
       cout << "------------------------------ "<<endl;
       cin >> chose1;
       switch (chose1){
       case 'p':
       case 'P':
          displayPatientDetails(AllPanel);
            break;
       case 'N':
       case 'n':
          displayPatientDetails(AllNonPanel);
            break;
       default:
            cout << "error input" <<endl;
            break;
       }
       break;

   case 'E':
   case 'e':
       system("cls");
       cout << "*** Thank you ***" << endl;
       myfile.open ("example.txt");
       SavePanelPatient(AllPanel, myfile);
       SaveNonPanelPatient(AllNonPanel, myfile);
       myfile.close();
       SaveConsultation(consult);

       return 0;
       break;
   default:
        {
    cout << "*** error input ****" << endl;
    cout << "****Enter the choise again ****" << endl;
    system("pause");
        }
        break;

   }

   }


}
