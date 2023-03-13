#include <iostream>
#include"tests_zbor.h"
#include"tests_repository.h"
#include"tests_service.h"
#include"tests_repo_file.h"
#include"ui.h"

int main()
{
    tests_zbor test_zbor;
    test_zbor.test_all();

    tests_repository test_repo;
    test_repo.test_all();

    tests_service test_service;
    test_service.test_all();

    tests_repo_file test_repo_file;
    test_repo_file.test_all();

    cout << "Testele din acest program au trecut ! \2";

    repository repo;
    service service(repo);
    ui ui(service);
    ui.run_menu();
}
