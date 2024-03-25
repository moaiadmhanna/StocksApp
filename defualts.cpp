//
// Created by Muayad Mhanna on 25.03.24.
//

#include "defualts.h"

std::string string_to_upper(std::string name){
    std::string resualt; // = "APPLE"
    for(int i = 0 ; i < name.length() ; i++){
        char upperCase = toupper(name[i]);
        resualt += upperCase;
    }
    return resualt;
}

unordered_map<string, string> tickerSymbolData = {
        {"APPLE", "AAPL"},
        {"MICROSOFT", "MSFT"},
        {"AMAZON", "AMZN"},
        {"ALPHABET", "GOOGL"},
        {"META", "META"},
        {"TESLA", "TSLA"},
        {"BERKSHIRE HATHAWAY", "BRK.A"},
        {"TENCENT HOLDINGS", "TCEHY"},
        {"ALIBABA GROUP HOLDING", "BABA"},
        {"JOHNSON & JOHNSON", "JNJ"},
        {"VISA", "V"},
        {"WALMART", "WMT"},
        {"PROCTER & GAMBLE", "PG"},
        {"NVIDIA", "NVDA"},
        {"MASTERCARD", "MA"},
        {"UNITEDHEALTH GROUP", "UNH"},
        {"THE HOME DEPOT", "HD"},
        {"DISNEY", "DIS"},
        {"BANK OF AMERICA", "BAC"},
        {"INTEL", "INTC"},
        {"NETFLIX", "NFLX"},
        {"ADOBE", "ADBE"},
        {"PAYPAL", "PYPL"},
        {"SALESFORCE.COM", "CRM"},
        {"INTERNATIONAL BUSINESS MACHINES", "IBM"},
        {"GENERAL ELECTRIC", "GE"},
        {"MCDONALD'S", "MCD"},
        {"CISCO SYSTEMS", "CSCO"},
        {"ORACLE CORPORATION", "ORCL"},
        {"PFIZER", "PFE"},
        {"COCA-COLA", "KO"},
        {"ACCENTURE", "ACN"},
        {"STARBUCKS", "SBUX"},
        {"3M", "MMM"},
        {"CHEVRON CORPORATION", "CVX"},
        {"EXXON MOBIL CORPORATION", "XOM"},
        {"VERIZON COMMUNICATIONS", "VZ"},
        {"AT&T", "T"},
        {"THE BOEING COMPANY", "BA"},
        {"NIKE", "NKE"},
        {"WELLS FARGO & COMPANY", "WFC"},
        {"PEPSICO", "PEP"},
        {"TARGET CORPORATION", "TGT"},
        {"COSTCO WHOLESALE CORPORATION", "COST"},
        {"THE GOLDMAN SACHS GROUP", "GS"},
        {"MERCK & CO.", "MRK"},
        {"FACEBOOK", "FB"},
        {"CITIGROUP INC.", "C"},
};