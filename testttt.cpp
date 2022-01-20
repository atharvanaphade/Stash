#include <bits/stdc++.h>

using namespace std;

class Movie_Data {
private:
    long long movie_id;
    double rating;
    string production_comp;
public:
    // get set methods
    void fetch_data(){} // fetches data form IMDB.
};

class Director {
private:
    string name;
    string production_comp;
public:
    // get set methods
};

class Actor {
private:
    string name;
    string production_comp;
public:
    // get set methods
};

class Movies {
private:
    Movie_Data metadata;
    string movie_name;
    vector<Director> dirs;
    vector<Actor> cast;
public:
    // get set methods
};

class Pay {
private:
    string billing_period;
    long long amount;
public:
    // get set methods
    void fetch_payment_data() {} // call the bank's api to make payments
    bool is_billing_expired() {}
};

class User {
private:
    Pay pay_details;
    string username;
    string password;
    vector<Movies> watch_list;
    vector<Actor> fav_cast;
public:
    // get set methods
    static void login(string username, string password) {} // login the user and call pay_details.is_billing_expired()
    static void create_user (string username, string password) {} // signup
    vector<Movies> recommend() {} // recommend movies according to taste
};

int main () {

}