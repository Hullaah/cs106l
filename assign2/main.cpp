/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <queue>
#include <set>
#include <string>
#include <sstream>

std::string kYourName = "Umar Adelowo"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  std::ifstream input{filename};
  std::set<std::string> applicants{};
  std::string name;
  while (std::getline(input, name)) {
    applicants.insert(name);
  }
  return applicants;
}

/**
 * Computes the initials of a students name
 *
 * @param  name The name whose initial is to be computed
 * @return The initials of student name
 */
std::string compute_initials(std::string &name) {
  std::stringstream s{name};
  std::string firstname, lastname;
  s >> firstname >> lastname;
  return std::string{firstname[0], lastname[0]};
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  std::queue<const std::string*> matches{};
  for (auto student : students) {
    if (compute_initials(name) == compute_initials(student)) {
      auto *student_ptr = &student;
      matches.push(student_ptr);
    }
  }
  return matches;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  return matches.empty() ? "NO MATCHES FOUND." : *matches.front();
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
