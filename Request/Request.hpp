#pragma once
#include "../config_file/server.hpp"
class Server;
class Request 
{
   public :
        //cgi
        int child_exited;
        int header_for_cgi_resp;
        clock_t time_of_child;
        int is_forked_before;
        int pipefd[2];
        pid_t pid_of_the_child;
        //

        int header_flag;
        int lenght_Readed;
        int lenght_of_content;
        int calcul_chunk_flag;    
        int flag_uri;
        int epol;
        int endOfrequest;
        int open_boundry_file;
        
        std::vector<std::string> myHeaders;
        std::string method;
        std::string target;
        std::string httpVersion;
        std::string status;
        std::ifstream fd_file;
        
        size_t chunk_size;
        size_t Bytes_readed;
        size_t chunked_file_size_response;

        std::string rest_of_boundry;
        std::ofstream outfile;
        std::string outfile_name;
        std::string uri_for_response;
        std::string boundary_separater;
        std::string extension;
        std::vector<std::pair<std::string, std::string> > StoreHeaders;
        std::string Post_status;
        std::string query;
        std::string content_type_python;
        std::string content_type;
        std::string content_lenght;
        std::string accept;
        std::map<std::string, std::string> pages;
        std::map<std::string, std::string> extensions;


    public :

        static int num_file;
        Request(std::string req, Server server);
        Request(Request const &req);
        Request();
        Request& operator=(Request const & req);
        
        //utils
        void ft_split(std::string input, std::string delimiter, std::vector<std::string> &parts);
        void split_rquest_v2(std::vector<std::string> &r, std::string &req, char c);
        int find_key(std::string key, std::vector<std::pair<std::string, std::string> > &postR);
        std::string valueOfkey(std::string key, std::vector<std::pair<std::string, std::string> > &postR);
        //

        //fill data
        void fill_method_type();
        void fill_query();
        void fill_headers();    
        void fill_extensions_map();
        void fill_error_pages_map();
        //

        //uri handling
        void long_uri(std::string &tar, Server &serv, int *flag_uri);
        void short_uri(std::string &tar, Server &serv, int *flag_uri);
        int count_slash(std::string tar);
        std::string replace_slash_in_target(Server &serv, std::string &targ, int *flag);
        void directory_moved_permanently();
        //
        //post
        void get_post_status();
        std::string get_separater(std::string val);
        //
        void generate_error_page(Server &server);
        void print_element();
        void error_handling(Server &serv);
        void Delete_methode();

        ~Request();
};