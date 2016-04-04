//
//  TigerNewsLetter.hpp
//  TigerAPI
//
//  Created by Wang zhen on 4/4/16.
//
//

#ifndef TigerNewsLetter_hpp
#define TigerNewsLetter_hpp

#include "TigerHttpClient.hpp"
#include "../../AppData.h"

#define MAILCHIMP_API_ERROR_401 401
#define MAILCHIMP_API_ERROR_400 400

namespace Tiger
{
    struct NewsLetterMemberData
    {
        std::string _mailMD5;
        std::string _mail;
        std::string _firstName;
        std::string _lastName;
    };
    
    class TigerNewsLetter
    {
    public:
        
        TigerNewsLetter();
        ~TigerNewsLetter();
        
        static TigerNewsLetter* getInstance();
        void destoryInstance();
        
        void addSubscriberToListID(const std::string& dataCenter,
                                   const std::string& listID,
                                   const NewsLetterMemberData& data,
                                   const bool isRunBackground);
        
        /*
            Listen http callback
         */
        bool listenHttpResult(HttpResponse *response);
        
    private:
        
        static TigerNewsLetter* _instance;
        
        bool _isRunBackground;
    };
    
};


#endif /* TigerNewsLetter_hpp */











