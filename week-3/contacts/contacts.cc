#include "contacts.h"

bool contacts_t::add(student_t student) {
    // TODO:
    // create student with given information and add to students
    // return true if add success else false
    // Students with duplicate IDs must not exist.
	if (student.id == -1) {
		return false;
	}

	for (size_t i = 0 ; i < m_size; i++){
		if (students[i].id == student.id) {
			return false;
		}
	}
	
	for (size_t i = 0 ; i < m_size; i++){ //if not
		if (students[i].id == -1){
			students[i].id = student.id;
			if (!student.name.empty()) {
				students[i].name = student.name;
			}	
			if (!student.phone.empty()) {
				students[i].phone = student.phone;
			}
			if (!student.mail.empty()) {
				students[i].mail = student.mail;
			}
			
			return true;
		}
	}

    return false;
}

bool contacts_t::add(int id, std::string name) {
    // TODO:
    // create student with given information and add to students
    // add the given student to the first empty space of students.
    // return true if add success else false
    // Students with duplicate IDs must not exist.
	student_t student;
	student.id = id;
	student.name = name;
	for (size_t i = 0 ; i < m_size; i++){
		if (students[i].id == student.id) {
			return false;
		}
	}
	
	for (size_t i = 0 ; i < m_size; i++){
		if (students[i].id == -1){
			students[i].id = student.id;
			students[i].name = student.name;

			return true;
		}
	}

    return false;
}

bool contacts_t::add(int id, std::string name, std::string phone) {
    // TODO:
    // create student with given information and add to students
    // add the given student to the first empty space of students.
    // return true if add success else false
    // Students with duplicate IDs must not exist.
	student_t student;
	student.id = id;
	student.name = name;
	student.phone = phone;

	for (size_t i = 0 ; i < m_size; i++){
		if (students[i].id == student.id) {
			return false;
		}
	}
	
	for (size_t i = 0 ; i < m_size; i++){
		if (students[i].id == -1){
			students[i].id = student.id;
			students[i].name = student.name;
			students[i].phone = student.phone;
			
			return true;
		}
	}

    return false;
}

bool contacts_t::add(int id, std::string name, std::string phone, std::string mail) {
    // TODO:
    // create student with given information and add to students
    // add the given student to the first empty space of students.
    // return true if add success else false
    // Students with duplicate IDs must not exist.
	student_t student;
	student.id = id;
	student.name = name;
	student.phone = phone;
	student.mail = mail;

	for (size_t i = 0 ; i < m_size; i++){
		if (students[i].id == student.id) {
			return false;
		}
	}
	
	for (size_t i = 0 ; i < m_size; i++){
		if (students[i].id == -1){
			students[i].id = id;
			students[i].name = student.name;
			students[i].phone = student.phone;
			students[i].mail = student.mail;
			
			return true;
		}
	}
    return false;
}

bool contacts_t::remove(int id) {
    // TODO:
    // remove student which match given id
    // return true after remove If can't find a student return false
	for (size_t i = 0 ; i < m_size; i++){
		if (students[i].id == id){
			students[i].id = -1;
			students[i].name.clear();
			students[i].phone.clear();
			students[i].mail.clear();
			
			return true;
		}
	}

    return false;
}

bool contacts_t::update(int id, std::string name, std::string phone, std::string mail) {
    // TODO:
    // Finds the student with the given ID and 
    // updates the information to the given values.
    // return true after update else false
	for (size_t i = 0 ; i < m_size; i++){
		if (students[i].id == id){
			students[i].name = name;
			students[i].phone = phone;
			students[i].mail = mail;
			return true;
		}
	}
	
    return false;
}

student_t contacts_t::find(int id) {
    // TODO:
    // return student which match given id
    // else, return {};
	for (size_t i = 0 ; i < m_size; i++){
		if (students[i].id == id) {
			return students[i];
		}
	}

    return {};
}

size_t contacts_t::size() {
    // TODO:
    // return number of students in contacts
	size_t check = 0;
	for (size_t i = 0 ; i < m_size ; i++){
		if (students[i].id != -1){
			check = check + 1;
		}
	}
	
	if (check != 0) {
		return check;
	}
	
    return 0;
}

