#pragma once
#include"repo_file.h"
class tests_repo_file
{
private:
    const string file_name = "file_name.txt";
    const string file_name_out = "file_name_out.txt";
    vector<zbor> zboruri;

    void test_add_zbor();
    void test_update_zbor();
    void test_delete_zbor();

    void test_load_from_file();
    void test_save_to_file();
public:
    tests_repo_file();
    ~tests_repo_file();
    void test_all();
};


