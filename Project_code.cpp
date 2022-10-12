/*
    Md. Taufik Hasan
    Department of CSE, DUET.

                    Code Defination:
My ID is 194095. So,last 3 digits of my ID is 095 mode by 20.Reminderis 15 now addition 1 with this reminder.
So,My Project number is 16.

16. Discount System.You are asked to write a discount system for a saloon, which provides service and sells
beauty products. It offers3 types of memberships Premium, Gold and Silver members receive a discount of 20%,
15% and 10% respectively. For all services provided customers without memberships receives no discount.
All members receive a flat 10% discount on product purchased (that might change in future)

*/

#include<iostream>
#include<iomanip>
#include<vector>
#include<iterator>
#include <algorithm>
using namespace std;
                             // Golobal veriable
int member=1,service=1,product=1;
                            // Global Function
int integer(){
    int a;
    cin>>a;
    while(1)
    {
        try
        {
            if(!cin.fail()){
                return a;
                break;
            }else
                throw "You have entered wrong input. Please a Enter Integer input : ";
        }
        catch(const char *msg)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<msg;
            cin>>a;
        }
    }

}

char option(){
    string line;
    level:
    getline(cin, line);
    try
    {
       if(line.length()==1 )
            return line[0];
       else
            throw "\nEnter only a single character : ";
    }
    catch(const char* msg)
    {
        cout<<msg;
        goto level;
    }
}


                              // Class concept of OOP
class Member{
    private:
        string member_name,DOB,contact, address, membership_type;
        int member_id,diposit,purchases_service_amount=0,purchases_product_amount=0;
        Member *next;

    public:
        void setter(){
            cout<<"\t"<<setw(35)<<"*************************************************"<<endl<<setw(35)<<left<<"\t\t\tNew Member Form"<<endl<<"\t"<<setw(35)<<"*************************************************"<<endl;
            member_id=member++;
            cout<<"\tNew Member ID : "<<member_id;
            cout<<"\n\tEnter Member Name : ";
            fflush(stdin);
            getline(cin,member_name);
            cout<<"\tEnter Member date of birth : ";
            getline(cin,DOB);
            cout<<"\tEnter Member address : ";
            getline(cin,address);
            cout<<"\tEnter Member Contact : ";
            cin>>contact;
            cout<<"\tEnter diposit : ";
            diposit=integer();
            update_membership();
            cout<<endl<<membership_type<<" Member Added Successfull :)\n";
            system("pause");
        }

        void set_purchases_amount(int purchases_amount){purchases_service_amount+=purchases_amount;}
        void set_purchases_price_amount(int purchases_amount){purchases_product_amount+=purchases_amount;}
        int get_member_id(){ return member_id;}
        int get_diposit(){return diposit;}
        string get_membership_type(){ return membership_type;}
        void update_membership(){
            if(diposit>=7000) membership_type="Premium";
            else if(diposit>=5000) membership_type="Gold";
            else if(diposit>=3000) membership_type="Silver";
            else membership_type="Genarel";
        }
        void update_membership(int cash){
            diposit+=cash;
            update_membership();
            cout<<"Now You are "<<membership_type<<" member :)\n";
        }

        friend ostream& operator<<(ostream& out, const Member &m);
};

                                        // Membership classes
class Premium: public Member{
    private:
        int percentage =20;
    public:
        void set(int percentage){
             this->percentage = percentage;
         }
        int get_percentage(){return percentage;}
};
class Gold:public Member{
    private:
        int percentage =15;
    public:
        void set(int percentage){
             this->percentage = percentage;
         }
        int get_percentage(){return percentage;}
};
class Silver:public Member{
    private:
        int percentage =10;
    public:
        void set(int percentage){
             this->percentage = percentage;
         }
        int get_percentage(){return percentage;}
};

class Flat_Discount{
    private:
        static int percentage;
    public:
        void set_flat_dicount(){
            cout<<"\tEnter Discount Rate : ";
            percentage=integer();
            cout<<"\tFlat Discount Updated Successfully\n";
            }
        int get_flat_discount(){return percentage;}
};
int Flat_Discount:: percentage=10;

class Services{
    private:
        string service_name, service_type, availability;
        int service_id=1, price;
    public:
        void setter(){
            cout<<"\t"<<setw(35)<<"*************************************************"<<endl<<setw(35)<<left<<"\t\t\tService Adding..."<<endl<<"\t"<<setw(35)<<"*************************************************"<<endl;
            service_id=service++;
            cout<<"\tNew service ID : "<<service_id;
            cout<<"\n\tEnter service Name : ";
            fflush(stdin);
            getline(cin,service_name);
            cout<<"\tEnter service type : ";
            getline(cin,service_type);
            cout<<"\tEnter service Availability (yes or no): ";
            cin>>availability;
            cout<<"\tEnter service price : ";
            price=integer();

            cout<<endl<<service_name<<" Service added succesfully :)\n";
            system("pause");
        }
        void set_price(int price){
            this->price=price;
            cout<<"\tPrice Updated Successfully\n";
        }
        void set_availibility(string s){
            this->availability=s;
            cout<<"\tAvailibility Updated Successfully\n";
        }

        int get_sirvice_id(){return service_id;};
        string get_sirvice_name(){ return service_name;};
        int get_sirvice_price(){return price;}

        bool service_availibility(){
            if(availability == "yes" || availability == "YES" || availability == "Yes"|| availability=="Y" ||availability=="y"){
                return true;
            }else return false;
        }

        friend ostream& operator<<(ostream& out, const Services& s);

};
                                // product class 
class Product{
    private:
        string product_name, product_type;
        int product_id, price, store_quantity,purchases_quantity;
    public:
        void setter(){
            cout<<"\t"<<setw(35)<<"*************************************************"<<endl<<setw(35)<<left<<"\t\t\tProduct Adding..."<<endl<<"\t"<<setw(35)<<"*************************************************"<<endl;
            product_id=product++;
            cout<<"\tNew Product ID : "<<product_id;
            cout<<"\n\tEnter Product Name : ";
            fflush(stdin);
            getline(cin,product_name);
            cout<<"\tEnter Product type : ";
            getline(cin,product_type);
            cout<<"\tEnter Product quantity : ";
            store_quantity=integer();
            cout<<"\tEnter per Product price : ";
            price=integer();

            cout<<endl<<product_name<<" Product added succesfully :)\n";
            system("pause");
        }
        void set_price(int price){
            this->price=price;
            cout<<"\tPrice Updated Successfully\n";
        }
        void set_purchase_quantity(int quantity){
            this->purchases_quantity=quantity;
        }
        void set_update_quantity(int quantity){
            this->store_quantity+=quantity;
            cout<<"\tNew Quantity Updated Successfully\n";
        }

        int get_product_id(){return product_id;};
        string get_product_name(){ return product_name;};
        int get_product_price(){return price;}
        int get_purchase_quantity(){return purchases_quantity;}
        int get_store_quantity(){return store_quantity;}

        bool product_availibility(int quantity){
            if(store_quantity>=quantity){
                store_quantity-=quantity;
                return true;
            }else return false;
        }

        friend ostream& operator<<(ostream& out, const Product& p);

};

ostream& operator<<(ostream& out, const Services &s){
    out<<"\t"<<setw(5)<<left<<s.service_id<<setw(15)<<left<<s.service_name<<setw(10)<<left<<s.service_type<<setw(8)<<left<<s.price<<setw(15)<<left<<s.availability<<endl;
    return out;
}
ostream& operator<<(ostream& out, const Product &p){
    out<<"\t"<<setw(5)<<left<<p.product_id<<setw(15)<<left<<p.product_name<<setw(10)<<left<<p.product_type<<setw(8)<<left<<p.price<<setw(15)<<left<<p.store_quantity<<endl;
    return out;
}
ostream& operator<<(ostream& out, const Member &m){
    out<<"\t"<<setw(5)<<left<<m.member_id<<setw(15)<<left<<m.member_name<<setw(10)<<left<<m.membership_type<<setw(8)<<left<<m.purchases_service_amount<<setw(8)<<left<<m.purchases_product_amount<<setw(15)<<left<<m.address<<endl;
    return out;
}

                         //Global vector and iterator
vector<Services>add_cart;
vector<Services>::iterator its;
vector<Product>product_cart;
vector<Product>::iterator itp;
vector<Member>::iterator itm;

                    // purchases_service Class 
class Purchases_Service:virtual public Services,virtual public Premium, virtual public Gold, virtual public Silver{
    private:
        int service_id, member_id,comition_rate, price=0;
        string membership_type;
        Member *member_object;
    public:
        void serviceID(){
            cout<<"\tEnter Service ID : ";
            service_id=integer();
        }
        void memberID(){
            cout<<"\tEnter Member ID : ";
            member_id=integer();
        }

        void check_service(vector<Services>v){
            int f=0;
            for(its=v.begin();its<v.end();its++){
                if(its->get_sirvice_id()==service_id){
                    f=1;
                    if(its->service_availibility()){
                        add_cart.push_back(*its);
                        cout<<add_cart.back().get_sirvice_name()<<" Service added to Cart\n";
                    }else{
                        cout<<"Service is not available right now\n";
                        }
                break;
                }
            }
            if(f==0){
                    cout<<"Your Enter Service id is not Found\n";
            }
        }

        bool check_member(vector<Member>*v){
            bool f=false;
            if(!v->empty()){
                for(itm=v->begin();itm<v->end();itm++){
                    if(itm->get_member_id()==member_id){
                        f=true;
                        member_object=&(*itm);
                        cout<<"\t"<<setw(35)<<"*************************************************"<<endl<<setw(35)<<left<<"\t\t\tMember Details"<<endl<<"\t"<<setw(35)<<"*************************************************"<<endl;
                        cout<<"\t"<<setw(5)<<left<<"ID"<<setw(15)<<left<<"Name"<<setw(10)<<left<<"Member"<<setw(8)<<left<<"Service"<<setw(8)<<left<<"Product"<<setw(15)<<left<<"Address"<<endl<<setw(50)<<"\t--------------------------------------------------"<<endl;
                        cout<<*(member_object);
                        //cout<<setw(50)<<"\t--------------------------------------------------"<<endl;
                        membership_type=member_object->get_membership_type();
                        if(membership_type=="Premium") comition_rate=Premium::get_percentage();
                        else if(membership_type=="Gold") comition_rate=Gold::get_percentage();
                        else if(membership_type=="Silver") comition_rate=Silver::get_percentage();
                        else comition_rate=0;
                        return true;
                        break;
                    }
                }if(!(f & true)) cout<<"Member ID not Found\n";
            }else cout<<"System Member is Empty!\n";

            return f;
        }

        bool check_cart(){
            if(!add_cart.empty()) return true;
            else return false;
        }

        void view_cart(){
            if(!add_cart.empty()){
                cout<<"\t"<<setw(5)<<left<<"ID"<<setw(15)<<left<<"Name"<<setw(25)<<right<<"Price"<<endl<<setw(50)<<"\t--------------------------------------------------"<<endl;
                for(its=add_cart.begin();its<add_cart.end();its++){
                        cout<<"\t"<<setw(5)<<left<<its->get_sirvice_id()<<setw(15)<<left<<its->get_sirvice_name()<<setw(25)<<right<<its->get_sirvice_price()<<endl;
                    }
            }else cout<<"Your Cart is Empty! Please Add Cart First\n";
        }

        void remove_cart(){
            int id,f=0;
            cout<<"\tEnter Service id : ";
            id=integer();
            if(!add_cart.empty()){
                for(its=add_cart.begin();its<add_cart.end();its++){
                    if((*its).get_sirvice_id()==id){
                        f=1;
                        add_cart.pop_back();
                        break;
                    }
                }
                if(f==1) cout<<"Service Successfully remove from your Cart\n";
                else cout<<"Service id Not Found Your Card, Please Add Card First\n";
            }else cout<<"Your Cart is Empty\n";
            system("pause");
        }

        void remove_cart_all(int flag){
            add_cart.clear();
            if(flag==0) cout<<"Successfully remove all Added services from your Cart\n";
            system("pause");
        }

        void payment(){
            price=0;
            cout<<"\t"<<setw(35)<<"*************************************************"<<endl<<setw(35)<<left<<"\t\t\tCart Details"<<endl<<"\t"<<setw(35)<<"*************************************************"<<endl;
            cout<<"\t"<<setw(5)<<left<<"ID"<<setw(15)<<left<<"Name"<<setw(25)<<right<<"Price"<<endl<<setw(50)<<"\t--------------------------------------------------"<<endl;
                for(its=add_cart.begin();its<add_cart.end();its++){
                price+=its->get_sirvice_price();
                cout<<"\t"<<setw(5)<<left<<its->get_sirvice_id()<<setw(15)<<left<<its->get_sirvice_name()<<setw(25)<<right<<its->get_sirvice_price()<<endl;
            }
            cout<<setw(50)<<"\t--------------------------------------------------"<<endl;
            cout<<"\t"<<setw(20)<<""<<setw(10)<<left<<"  Total Price ="<<setw(10)<<right<<price<<"/="<<endl;
            cout<<"\t"<<setw(6)<<"After "<<comition_rate<<setw(20)<<left<<"% discount Payable amount ="<<setw(10)<<right<<price-(price*comition_rate)/100<<"/="<<endl;


        }

        void purchase_history(){
            member_object->set_purchases_amount(price);
            cout<<"\tThank You. Stay with us :)\n";
        }

        void update_membership(){
            int cash;
            if(membership_type=="Premium") cout<<"\tCongratulation, You already our Premium member. Please stay with us";
            else if(membership_type=="Gold") {
                cout<<"\tCongratulation, You are our Gold member.\n\tEnter "<<7000-member_object->get_diposit()<<" BDT for get Premium membeship\n";
                cout<<"Enter amount : ";cin>>cash;
                member_object->update_membership(cash);
            }
            else if(membership_type=="Silver") {
                cout<<"\tCongratulation, You are our Silver member.\n\tEnter "<<7000-member_object->get_diposit()<<" BDT for get Premium membeship\n\tEnter "<<5000-member_object->get_diposit()<<" BDT for get Gold membeship\n";
                cout<<"Enter amount : ";cin>>cash;
                member_object->update_membership(cash);
            }
            else{
                cout<<"\tYou are our Genarel member.\n\tEnter "<<7000-member_object->get_diposit()<<" BDT for get Premium membeship\n\tEnter "<<5000-member_object->get_diposit()<<" BDT for get Gold membeship\n\tEnter "<<3000-member_object->get_diposit()<<" BDT for get Silver membeship\n";
                cout<<"Enter amount : ";cin>>cash;
                member_object->update_membership(cash);
            }
        }

        void update(vector<Services>*service){
            if(!service->empty()){
                char input;
                int id,f;
                string s;

                cout<<"\t"<<setw(35)<<"*************************************************"<<endl<<setw(35)<<left<<"\t\t\tOur Services"<<endl<<"\t"<<setw(35)<<"*************************************************"<<endl;
                cout<<"\t"<<setw(5)<<left<<"ID"<<setw(15)<<left<<"Name"<<setw(10)<<left<<"Type"<<setw(8)<<left<<"Price"<<setw(15)<<left<<"Availibility"<<endl<<setw(50)<<"\t--------------------------------------------------"<<endl;
                for(its=service->begin();its<service->end();its++)
                    cout<<(*its);
                cout<<"\t"<<setw(50)<<"--------------------------------------------------"<<endl;

                level:
                cout<<"\n\t1. Update Price\n\t2. Update Availibility\n\t3. Return Main Menu\nChoose Your option  ";
                input=option();
                if(input=='1'){
                    cout<<"\tEnter Service ID : ";
                    id=integer();
                    f=0;
                    for(its=service->begin();its<service->end();its++){
                        if(its->get_sirvice_id()==id){
                            f=1;
                            cout<<"\tEnter Your Updated Price : ";
                            cin>>price;
                            its->set_price(price);
                            break;
                        }
                    }
                    if(f==0) cout<<"\tService ID not Found.\n";
                }else if(input=='2'){
                    cout<<"\tEnter Service ID : ";
                    id=integer();
                    f=0;
                    for(its=service->begin();its<service->end();its++){
                        if(its->get_sirvice_id()==id){
                            f=1;
                            cout<<"\tEnter Your Updated Availibility : ";
                            cin>>s;
                            its->set_availibility(s);
                        }
                    }if(f==0) cout<<"\tService ID not Found.\n";
                }else if(input=='3'){

                }else{
                    cout<<"\tEnter valid input\n";
                    goto level;
                }

            }else cout<<"\tNo service Found, Please Add Services\n";
        }


};
                    // purchase_product class 
class Purchases_Product: public Product, public Flat_Discount,  public Member{
    private:
        int product_id,quantity, member_id,price=0;
        string name;
        Member *member_object;
    public:
        void productID(){
            cout<<"\tEnter Product ID : ";
            product_id=integer();
            cout<<"\tEnter Product Quantity : ";
            quantity=integer();
        }
        void memberID(){
            cout<<"\tEnter Member ID : ";
            member_id=integer();
        }

        void check_product(vector<Product>*v){
            int f=0;
            for(itp=v->begin();itp<v->end();itp++){
                if(itp->get_product_id()==product_id){
                    if(itp->product_availibility(quantity)){
                        f=1;
                        itp->set_purchase_quantity(quantity);
                        product_cart.push_back(*itp);
                        cout<<product_cart.back().get_product_name()<<" Product added to Cart\n";
                    }else{
                        cout<<"Product quantity is not available right now\n";
                        }
                break;
                }
            }
            if(f==0){
                    cout<<"Your Enter Product id is not Found\n";
                }
        }

        bool check_member(vector<Member>*v){
            bool f=false;
            if(!v->empty()){
                for(itm=v->begin();itm<v->end();itm++){
                    if(itm->get_member_id()==member_id){
                        f=true;
                        member_object= &(*itm);
                        cout<<"\t"<<setw(35)<<"*************************************************"<<endl<<setw(35)<<left<<"\t\t\tMember Details"<<endl<<"\t"<<setw(35)<<"*************************************************"<<endl;
                        cout<<"\t"<<setw(5)<<left<<"ID"<<setw(15)<<left<<"Name"<<setw(10)<<left<<"Member"<<setw(8)<<left<<"Service"<<setw(8)<<left<<"Product"<<setw(15)<<left<<"Address"<<endl<<setw(50)<<"\t--------------------------------------------------"<<endl;
                        cout<<(*itm);
                        break;
                    }
                }
                if(!(f & true)) cout<<"Member ID not Found\n";
            }else cout<<"System Member is Empty!\n";

            return f;
        }

        bool check_cart(){
            if(!product_cart.empty()) return true;
            else return false;
        }

        void remove_cart(){
            int id,f=0;
            cout<<"\tEnter product id : ";
            id=integer();
            if(!product_cart.empty()){
                for(itp=product_cart.begin();itp<product_cart.end();itp++){
                    if((*itp).get_product_id()==id){
                        f=1;
                        product_cart.pop_back();
                        break;
                    }
                }
                if(f==1) cout<<"Product Successfully remove from your Cart\n";
                else cout<<"Product id Not Found Your Card, Please Add Card First\n";
            }else cout<<"Your Cart is Empty\n";
            system("pause");
        }

        void remove_cart_all(int flag){
            product_cart.clear();
            if(flag==0) cout<<"Successfully remove all Added products from your Cart\n";
        }

        void payment(){
            price=0;
            if(!product_cart.empty()){
                cout<<"\t"<<setw(35)<<"*************************************************"<<endl<<setw(35)<<left<<"\t\t\tCart Details"<<endl<<"\t"<<setw(35)<<"*************************************************"<<endl;
                cout<<"\t"<<setw(5)<<left<<"ID"<<setw(15)<<left<<"Name"<<setw(10)<<left<<setw(8)<<left<<"Price"<<setw(15)<<left<<"Quantity"<<endl<<setw(50)<<"\t--------------------------------------------------"<<endl;
                    for(itp=product_cart.begin();itp<product_cart.end();itp++){
                    price+=((*itp).get_product_price())*((*itp).get_purchase_quantity());
                    cout<<"\t"<<setw(5)<<left<<(*itp).get_product_id()<<setw(15)<<left<<(*itp).get_product_name()<<setw(10)<<left<<setw(8)<<left<<(*itp).get_product_price()<<setw(15)<<left<<(*itp).get_purchase_quantity()<<endl;
                }
                cout<<setw(50)<<"\t--------------------------------------------------"<<endl;
                cout<<"\t"<<setw(20)<<""<<setw(10)<<left<<" Total Price = "<<setw(10)<<right<<price<<"/="<<endl;
                cout<<"\t"<<setw(6)<<"After "<<Flat_Discount::get_flat_discount()<<setw(20)<<left<<"% discount Payable amount ="<<setw(10)<<right<<price-(price*Flat_Discount::get_flat_discount())/100<<"/="<<endl;

            }else cout<<"Your Cart is Empty! Please Add Cart First\n";

        }

        void purchase_history(){
            member_object->set_purchases_price_amount(price);
            cout<<"\tThank You. Stay with us :)\n";
        }

        void update(vector<Product>*product){
            if(!product->empty()){
                char input;
                int id,q,f;
                system("CLS");
                cout<<"\t"<<setw(35)<<"*************************************************"<<endl<<setw(35)<<left<<"\t\t\tOur Products"<<endl<<"\t"<<setw(35)<<"*************************************************"<<endl;
                cout<<"\t"<<setw(5)<<left<<"ID"<<setw(15)<<left<<"Name"<<setw(10)<<left<<"Type"<<setw(8)<<left<<"Price"<<setw(15)<<left<<"Store Quantity"<<endl<<setw(50)<<"\t--------------------------------------------------"<<endl;
                for(itp=product->begin();itp<product->end();itp++){
                    cout<<(*itp);
                }
                cout<<"\t"<<setw(50)<<"--------------------------------------------------"<<endl;

                level:
                cout<<"\n\t1. Update Price\n\t2. Update Quantity\n\t3. Return Main Menu\nChoose Your option  ";
                input=option();
                if(input=='1'){
                    cout<<"\tEnter Product ID : ";
                    id=integer();
                    f=0;
                    for(itp=product->begin();itp<product->end();itp++){
                        if(itp->get_product_id()==id){
                            f=1;
                            cout<<"\tEnter Your Updated Price : ";
                            price=integer();
                            itp->set_price(price);
                        }
                    }if(f==0) cout<<"\tProduct ID not Found.\n";
                }else if(input=='2'){
                    cout<<"\tEnter Product ID : ";
                    id=integer();
                    f=0;
                    for(itp=product->begin();itp<product->end();itp++){
                        if(itp->get_product_id()==id){
                            f=1;
                            cout<<"\tEnter Your New Added Quantity : ";
                            q=integer();
                            itp->set_update_quantity(q);
                        }
                    }if(f==0) cout<<"\tProduct ID not Found.\n";
                }else if(input=='3'){

                }else{
                    cout<<"\tEnter valid input\n";
                    goto level;
                }

            }else cout<<"\tNo Product Found, Please Add product\n";
        }
};



                        // Main Function
int main(){
    char input;
    vector<Member>member;
    vector<Services>service;
    vector<Product>product;


    menu: // main level
    system("CLS"); // for screen clear
    cout<<"\n\t"<<setw(35)<<"****************************************************"<<endl<<"\t"<<setw(20)<<right<<"Project Name : "<<setw(35)<<left<<"\tDiscount System for a Saloon"<<endl;
    cout<<"\t"<<setw(20)<<right<<"Project ID : "<<setw(35)<<left<<"\t194095"<<endl<<"\t"<<setw(35)<<"****************************************************"<<endl;
    cout<<"\t1. Add Service \n\t2. Add Product \n\t3. Add Member \n\t4. Purchase Service "<<endl;
    cout<<"\t5. Purchase Product \n\t6. Change Flat Discount \n\t7. Update Service \n\t8. Update Producrt \n\t9. Exit \n";
                // class object declararion 
    Purchases_Service s;
    Purchases_Product p;
    Services ser;
    Product pro;
    Member m;
                    // while loop running while user don't input exit program 
    while (true)
    {
        cout<<"\nEnter Your Choose  ";
        input=option();
        if(input=='1'){
            ser.setter();
            service.push_back(ser);
            system("CLS");
            goto menu;

        }else if(input=='2'){
            pro.setter();
            product.push_back(pro);
            system("CLS");
            goto menu;
        }
        else if(input=='3'){
            m.setter();
            member.push_back(m);
            system("CLS");
            goto menu;
        }                                                         // Service purchase
        else if(input=='4'){
            service_menu:
            if(!service.empty()){
                system("CLS");
                cout<<"\t"<<setw(35)<<"*************************************************"<<endl<<setw(35)<<left<<"\t\t\tOur Services"<<endl<<"\t"<<setw(35)<<"*************************************************"<<endl;
                cout<<"\t"<<setw(5)<<left<<"ID"<<setw(15)<<left<<"Name"<<setw(10)<<left<<"Type"<<setw(8)<<left<<"Price"<<setw(15)<<left<<"Availibility"<<endl<<setw(50)<<"\t--------------------------------------------------"<<endl;
                for(its=service.begin();its<service.end();its++){
                    cout<<(*its);
                }
                cout<<"\t"<<setw(50)<<"--------------------------------------------------"<<endl;
                service_level:
                cout<<"\t1. Add cart\n\t2. Remove Cart\n\t3. View Cart\n\t4. Purchase service\n\t5. Return Main Menu\nChoice Your option ";
                while(true){
                    input=option();
                    if(input=='1'){
                        s.serviceID();
                        s.check_service(service);
                        system("pause");
                        goto service_menu;
                    }else if(input=='2'){
                        s.remove_cart();
                        goto service_menu;
                    }else if(input=='3'){
                        s.view_cart();
                        system("pause");
                        goto service_menu;
                    }else if(input=='4'){
                        update_membership:
                        s.memberID();
                        system("CLS");
                        if(s.check_member(&member) && s.check_cart()){
                            s.payment();
                            cout<<"\n\t1. Confirm purchase \n\t2. Update MemberShip\n\t3. Remove All Service from Cart\n\t4. Add other Service to cart\n\t5. Return Main Menu\nChoice Your option ";
                            while(true){
                                input=option();
                                if(input=='1'){
                                    s.purchase_history();
                                    s.remove_cart_all(1);
                                    system("pause");
                                    goto menu;
                                }else if(input=='2'){
                                    s.update_membership();
                                    system("pause");
                                    system("CLS");
                                    goto update_membership;
                                }else if(input=='3'){
                                    s.remove_cart_all(0);
                                    goto service_menu;
                                }else if(input=='4'){
                                    goto service_menu;
                                    break;
                                }
                                else if(input=='5'){
                                    goto menu;
                                    break;
                                }else{
                                    cout<<"Plase Enter a valid Input"<<endl;
                                }
                            }
                        }else{
                            system("pause");
                            system("CLS");
                            goto service_menu;
                        }
                    }else if(input=='5'){
                        goto menu;
                        break;
                    }else{
                        cout<<"Plase Enter a valid Input"<<endl;
                    }
                }
            }else cout<<"No service Found\n";

        }                                                           // product services
        else if(input=='5'){
                        product_menu:
                        if(!product.empty()){
                            system("CLS");
                            cout<<"\t"<<setw(35)<<"*************************************************"<<endl<<setw(35)<<left<<"\t\t\tOur Products"<<endl<<"\t"<<setw(35)<<"*************************************************"<<endl;
                            cout<<"\t"<<setw(5)<<left<<"ID"<<setw(15)<<left<<"Name"<<setw(10)<<left<<"Type"<<setw(8)<<left<<"Price"<<setw(15)<<left<<"Store Quantity"<<endl<<setw(50)<<"\t--------------------------------------------------"<<endl;
                            for(itp=product.begin();itp<product.end();itp++){
                                cout<<(*itp);
                            }
                            cout<<"\t"<<setw(50)<<"--------------------------------------------------"<<endl;
                            product_level:
                            cout<<"\t1. Add cart\n\t2. Remove Cart\n\t3. View Cart\n\t4. Purchase service\n\t5. Return Main Menu\nChoice Your option ";
                            while(true){
                                input=option();
                                if(input=='1'){
                                    p.productID();
                                    p.check_product(&product);
                                    system("pause");
                                    goto product_menu;
                                }else if(input=='2'){
                                    p.remove_cart();
                                    goto product_menu;
                                }else if(input=='3'){
                                    p.payment();
                                    system("pause");
                                    goto product_menu;
                                }else if(input=='4'){
                                    loop:
                                    cout<<"\tDo you have a member ID?  Y / N : ";
                                    input=option();
                                    if(input=='Y' || input=='y'){
                                        p.memberID();
                                        system("CLS");
                                        if(p.check_member(&member) && p.check_cart()){
                                            p.payment();
                                            cout<<"\n\t1. Confirm purchase \n\t2. Remove All Service from Cart\n\t3. Add other Service to cart\n\t4. Return Main Menu\nChoice Your option ";
                                            while(true){
                                                input=option();
                                                if(input=='1'){
                                                    p.remove_cart_all(1);
                                                    p.purchase_history();
                                                    system("pause");
                                                    goto menu;
                                                }else if(input=='2'){
                                                    p.remove_cart_all(0);
                                                    goto product_menu;
                                                }else if(input=='3'){
                                                    goto product_menu;
                                                    break;
                                                }
                                                else if(input=='4'){
                                                    goto menu;
                                                    break;
                                                }else{
                                                    cout<<"Plase Enter a valid Input"<<endl;
                                                }
                                            }
                                        }else{
                                            system("pause");
                                            system("CLS");
                                            goto product_menu;
                                        }
                                    }else if(input=='N' || input=='n'){
                                        if(p.check_cart()){
                                             p.payment();
                                            cout<<"\n\t1. Confirm purchase \n\t2. Remove All Service from Cart\n\t3. Add other Service to cart\n\t4. Return Main Menu\nChoice Your option ";
                                            while(true){
                                                input=option();
                                                if(input=='1'){
                                                    p.remove_cart_all(1);
                                                    cout<<"Thanks, Stay with us :)\n";
                                                    system("pause");
                                                    goto menu;
                                                }else if(input=='2'){
                                                    p.remove_cart_all(0);
                                                    goto product_level;
                                                }else if(input=='3'){
                                                    goto product_level;
                                                    break;
                                                }
                                                else if(input=='4'){
                                                    goto menu;
                                                    break;
                                                }else{
                                                    cout<<"Plase Enter a valid Input"<<endl;
                                                }
                                            }
                                        }else{
                                            cout<<"\tYour Cart is Empty!\n";
                                            system("pause");
                                            system("CLS");
                                            goto product_menu;
                                        }

                                    }else{
                                        cout<<"Enter valid input\n";
                                        goto loop;
                                    }


                                }else if(input=='5'){
                                    goto menu;
                                    break;
                                }else{
                                    cout<<"Plase Enter a valid Input"<<endl;
                                }
                            }

                        }else cout<<"No Products are Found\n";
        }                                                       // Change Flat Discount
        else if(input=='6'){
            Flat_Discount f;
            f.set_flat_dicount();
            system("pause");
            system("CLS");
            goto menu;
        }
        else if(input=='7'){
            s.update(&service);
            system("pause");
            system("CLS");
            goto menu;
        }
        else if(input=='8'){
            p.update(&product);
            system("pause");
            system("CLS");
            goto menu;
        }
        else if(input=='9'){
            exit(1);
        }
        else {
            cout<<"Plase Enter a valid Input"<<endl;
            system("pause");
            goto menu;
        }
    }


    return 0;
}

                            // End of my project ID 194095