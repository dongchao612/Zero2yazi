#ifndef JSON_H__
#define JSON_H__

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

namespace Zero2yazi {
namespace json {
    class Json {
    public:
        enum Type { json_null = 0, json_bool, json_int, json_double, json_string, json_array, json_object };

        Json();
        Json( bool value );
        Json( int value );
        Json( double value );
        Json( const char* value );
        Json( const string& value );
        Json( Type type );
        Json( const Json& other );

    private:
        union Value {
            bool                m_bool;
            int                 m_int;
            double              m_double;
            string*             m_string;
            vector< Json >*     m_array;
            map< string, Json > m_object;
        };

        Type  m_type;
        Value m_value;
    };

}  // namespace json

}  // namespace Zero2yazi

#endif  // JSON_H__