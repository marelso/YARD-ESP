#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>

class FirebaseHandler {
    private:
        const String API_KEY = "";
        const String API_URL = "";
        bool isSignUpOk = false;
        String uid;
        FirebaseConfig config;
        FirebaseAuth auth;

        void init() {
            if(Firebase.signUp(&config, &auth, "", "")) {
                isSignUpOk = true;
                Serial.println("Successfully signUp to firebase.");

                setUID();

                config.token_status_callback = tokenStatusCallback;

                Firebase.begin(&config, &auth);
                Firebase.reconnectWiFi(true);
                Serial.println("Successfully connected to firebase.");
            }
        }

        void setUID() {
            Serial.println("Getting user UID.");

            while (auth.token.uid == "") {
                Serial.print(".");
                delay(1000);
            }
            
            uid = auth.token.uid.c_str();
        }

    public:
        FirebaseHandler() {
            config.api_key = API_KEY;
            config.database_url = API_URL;
        }
};