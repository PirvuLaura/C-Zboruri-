#include "tests_repo_file.h"
#include<cassert>

void tests_repo_file::test_add_zbor()
{
    repo_file repoFile = repo_file(this->file_name);
    repoFile.set_file_name(this->file_name_out);
    zbor z(1122, "Arad", "Bucuresti", "23-05-2021", "dus-intors", 200);
    repoFile.add_zbor(z);
    assert(repoFile.get_size() == this->zboruri.size() + 1);
    assert(repoFile.get_all()[repoFile.get_size() - 1] == z);
}

void tests_repo_file::test_update_zbor()
{
    repo_file repoFile = repo_file(this->file_name);
    repoFile.set_file_name(this->file_name_out);
    zbor z(1122, "Arad", "Bucuresti", "23-05-2021", "dus-intors", 200);
    repoFile.update_zbor(this->zboruri[1], z);
    assert(repoFile.get_all()[0] == this->zboruri[0]);
    assert(repoFile.get_all()[1] == z);
}

void tests_repo_file::test_delete_zbor()
{
    repo_file repoFile = repo_file(this->file_name);
    repoFile.set_file_name(this->file_name_out);
    repoFile.delete_zbor(this->zboruri[0]);
    assert(repoFile.get_size() == 1);
    assert(repoFile.get_all()[0] == this->zboruri[1]);
    zbor z(1122, "Arad", "Bucuresti", "23-05-2021", "dus-intors", 200);
    repoFile.delete_zbor(z);
    assert(repoFile.get_size() == 1);
    assert(repoFile.get_all()[0] == this->zboruri[1]);
}

void tests_repo_file::test_load_from_file()
{
    repo_file repoFile = repo_file(this->file_name); //se face automat load
    assert(repoFile.get_size() == this->zboruri.size());
    for (int i = 0; i < this->zboruri.size(); i++)
    {
        assert(repoFile.get_all()[i] == this->zboruri[i]);
    }
}

void tests_repo_file::test_save_to_file()
{
    repo_file repoFile = repo_file(this->file_name);  
    repoFile.set_file_name(this->file_name_out);   //se face automat save
    zbor z(1122, "Arad", "Bucuresti", "23-05-2021", "dus-intors", 200);
    repoFile.add_zbor(z);
    assert(repoFile.get_size() == this->zboruri.size() + 1);
    vector<zbor> all = repoFile.get_all();
    for (int i = 0; i < repoFile.get_size() - 1; i++)
    {
        assert(this->zboruri[i] == all[i]);
    }
    assert(all[all.size() - 1] == z);
}

tests_repo_file::tests_repo_file()
{
    zbor z1(1111, "Arad", "Cluj", "22-12-2021", "one-way", 450);
    zbor z2(2323, "Valcea", "Sibiu", "08-08-2008", "dus-intors", 500);
    this->zboruri.push_back(z1);
    this->zboruri.push_back(z2);
}

tests_repo_file::~tests_repo_file()
{
}

void tests_repo_file::test_all()
{
    test_add_zbor();
    test_update_zbor();
    test_delete_zbor();

    test_load_from_file();
    test_save_to_file();
}
