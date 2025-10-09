//copyright 2025

#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
#include "Customers.h"
#include "Customer.h"
#include "Contact.h"
#include "Charge.h"
#include "ListOfCharge.h"
#include "BTNode.h"
#include <list>
#include <sstream>

class newCxxTest : public CxxTest::TestSuite {
public:

    void testChargeDefaultConstructor() {
        Charge c;
        TS_ASSERT_EQUALS(c.GetAmount(), 0.0);
        TS_ASSERT_EQUALS(c.GetBusiness(), "");
    }

    void testChargeGetBusiness() {
        Charge c("Target", 100.0);
        TS_ASSERT_EQUALS(c.GetBusiness(), "Target");
    }

    void testContactDefaultConstructor() {
        Contact c;
        TS_ASSERT_EQUALS(c.getName(), "");
        TS_ASSERT_EQUALS(c.getAddress(), "");
        TS_ASSERT_EQUALS(c.getEmail(), "");
    }

    void testContactGetters() {
        Contact c("John Doe", "123 Main St", "john@example.com");
        TS_ASSERT_EQUALS(c.getName(), "John Doe");
        TS_ASSERT_EQUALS(c.getAddress(), "123 Main St");
        TS_ASSERT_EQUALS(c.getEmail(), "john@example.com");
    }

    void testContactSetters() {
        Contact c;
        c.setName("Jane Smith");
        c.setAddress("456 Elm St");
        c.setEmail("jane@example.com");
        TS_ASSERT_EQUALS(c.getName(), "Jane Smith");
        TS_ASSERT_EQUALS(c.getAddress(), "456 Elm St");
        TS_ASSERT_EQUALS(c.getEmail(), "jane@example.com");
    }

    void testContactOutputStream() {
        Contact c("John Doe", "123 Main St", "john@example.com");
        std::ostringstream oss;
        oss << c;
        std::string result = oss.str();
        TS_ASSERT(result.find("John Doe") != std::string::npos);
        TS_ASSERT(result.find("123 Main St") != std::string::npos);
        TS_ASSERT(result.find("john@example.com") != std::string::npos);
    }

    void testCustomerDefaultConstructor() {
        Customer c;
        TS_ASSERT_EQUALS(c.GetCard_number(), "");
        TS_ASSERT_EQUALS(c.GetLimit(), 0.0);
    }

    void testCustomerGetCardNumber() {
        Contact contact("John Doe", "123 Main St", "john@example.com");
        list<Charge> charges;
        Customer c("1234", contact, 1000.0, charges);
        TS_ASSERT_EQUALS(c.GetCard_number(), "1234");
    }

    void testCustomerSetCardNumber() {
        Customer c;
        c.SetCard_number("5678");
        TS_ASSERT_EQUALS(c.GetCard_number(), "5678");
    }

    void testCustomerGetContact() {
        Contact contact("John Doe", "123 Main St", "john@example.com");
        list<Charge> charges;
        Customer c("1234", contact, 1000.0, charges);
        Contact retrieved = c.GetContact();
        TS_ASSERT_EQUALS(retrieved.getName(), "John Doe");
    }

    void testCustomerSetContact() {
        Customer c;
        Contact contact("Jane Smith", "456 Elm St", "jane@example.com");
        c.SetContact(contact);
        Contact retrieved = c.GetContact();
        TS_ASSERT_EQUALS(retrieved.getName(), "Jane Smith");
    }

    void testCustomerSetCharges() {
        Customer c;
        list<Charge> charges;
        charges.push_back(Charge("Store A", 100.0));
        c.SetCharges(charges);
        TS_ASSERT_EQUALS(c.GetCharges().size(), 1);
    }

    void testCustomerPushBack() {
        Contact contact("John Doe", "123 Main St", "john@example.com");
        list<Charge> charges;
        Customer c("1234", contact, 1000.0, charges);
        c.push_back(Charge("Store B", 50.0));
        TS_ASSERT_EQUALS(c.GetCharges().size(), 1);
    }

    void testCustomerOutputStream() {
        Contact contact("John Doe", "123 Main St", "john@example.com");
        list<Charge> charges;
        Customer c("1234", contact, 1000.0, charges);
        std::ostringstream oss;
        oss << c;
        std::string result = oss.str();
        TS_ASSERT(result.find("1234") != std::string::npos);
    }

    void testListOfCharge() {
        ListOfCharge loc;
        loc.addCharge(Charge("Store A", 100.0));
        loc.addCharge(Charge("Store B", 200.0));
        list<Charge> charges = loc.getCharges();
        TS_ASSERT_EQUALS(charges.size(), 2);
    }

    void testBinarySearchTreeErase() {
        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "john@example.com");
        list<Charge> charges1;
        Customer customer1("1111", contact1, 1000.0, charges1);
        customers.insert(customer1);

        TS_ASSERT(customers.erase(customer1));

        Contact temp_contact("", "", "");
        list<Charge> temp_charges;
        Customer temp("1111", temp_contact, 0.0, temp_charges);
        const Customer* found = customers.find(temp);
        TS_ASSERT_EQUALS(found, (const Customer*)NULL);
    }

    void testBinarySearchTreeEraseNotFound() {
        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "john@example.com");
        list<Charge> charges1;
        Customer customer1("1111", contact1, 1000.0, charges1);

        TS_ASSERT(!customers.erase(customer1));
    }

    void testBinarySearchTreeEraseLeftOnly() {
        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "john@example.com");
        Contact contact2("Jane Smith", "456 Elm St", "jane@example.com");
        list<Charge> charges;
        Customer customer1("2222", contact1, 1000.0, charges);
        Customer customer2("1111", contact2, 1500.0, charges);

        customers.insert(customer1);
        customers.insert(customer2);
        customers.erase(customer1);

        Contact temp_contact("", "", "");
        list<Charge> temp_charges;
        Customer temp("1111", temp_contact, 0.0, temp_charges);
        const Customer* found = customers.find(temp);
        TS_ASSERT_DIFFERS(found, (const Customer*)NULL);
    }

    void testBinarySearchTreeEraseRightOnly() {
        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "john@example.com");
        Contact contact2("Jane Smith", "456 Elm St", "jane@example.com");
        list<Charge> charges;
        Customer customer1("1111", contact1, 1000.0, charges);
        Customer customer2("2222", contact2, 1500.0, charges);

        customers.insert(customer1);
        customers.insert(customer2);
        customers.erase(customer1);

        Contact temp_contact("", "", "");
        list<Charge> temp_charges;
        Customer temp("2222", temp_contact, 0.0, temp_charges);
        const Customer* found = customers.find(temp);
        TS_ASSERT_DIFFERS(found, (const Customer*)NULL);
    }

    void testBinarySearchTreeEraseTwoChildren() {
        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "john@example.com");
        Contact contact2("Jane Smith", "456 Elm St", "jane@example.com");
        Contact contact3("Bob Brown", "789 Oak St", "bob@example.com");
        list<Charge> charges;
        Customer customer1("2222", contact1, 1000.0, charges);
        Customer customer2("1111", contact2, 1500.0, charges);
        Customer customer3("3333", contact3, 2000.0, charges);

        customers.insert(customer1);
        customers.insert(customer2);
        customers.insert(customer3);
        customers.erase(customer1);

        Contact temp_contact("", "", "");
        list<Charge> temp_charges;
        Customer temp("1111", temp_contact, 0.0, temp_charges);
        const Customer* found = customers.find(temp);
        TS_ASSERT_DIFFERS(found, (const Customer*)NULL);
    }

    void testBinarySearchTreeInsertLeft() {
        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "john@example.com");
        Contact contact2("Jane Smith", "456 Elm St", "jane@example.com");
        list<Charge> charges;
        Customer customer1("2222", contact1, 1000.0, charges);
        Customer customer2("1111", contact2, 1500.0, charges);

        customers.insert(customer1);
        customers.insert(customer2);

        Contact temp_contact("", "", "");
        list<Charge> temp_charges;
        Customer temp("1111", temp_contact, 0.0, temp_charges);
        const Customer* found = customers.find(temp);
        TS_ASSERT_DIFFERS(found, (const Customer*)NULL);
    }

    void testBinarySearchTreeInsertDuplicate() {
        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "john@example.com");
        list<Charge> charges;
        Customer customer1("1111", contact1, 1000.0, charges);

        TS_ASSERT(customers.insert(customer1));
        TS_ASSERT(!customers.insert(customer1));
    }

    void testCountBigLimitsEmpty() {
        Customers<Customer> customers;
        TS_ASSERT_EQUALS(customers.count_big_limits(1000.0), 0);
    }

    void testCountBigLimitsOne() {
        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "john@example.com");
        list<Charge> charges1;
        Customer customer1("1111", contact1, 2000.0, charges1);
        customers.insert(customer1);

        TS_ASSERT_EQUALS(customers.count_big_limits(1500.0), 1);
        TS_ASSERT_EQUALS(customers.count_big_limits(2500.0), 0);
    }

    void testCountBigLimitsMultiple() {
        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "john@example.com");
        Contact contact2("Jane Smith", "456 Elm St", "jane@example.com");
        Contact contact3("Bob Brown", "789 Oak St", "bob@example.com");

        list<Charge> charges1;
        Customer customer1("1111", contact1, 1000.0, charges1);
        Customer customer2("2222", contact2, 2500.0, charges1);
        Customer customer3("3333", contact3, 3500.0, charges1);

        customers.insert(customer1);
        customers.insert(customer2);
        customers.insert(customer3);

        TS_ASSERT_EQUALS(customers.count_big_limits(1500.0), 2);
        TS_ASSERT_EQUALS(customers.count_big_limits(500.0), 3);
        TS_ASSERT_EQUALS(customers.count_big_limits(4000.0), 0);
    }

    void testAnyOverLimitEmpty() {
        Customers<Customer> customers;
        TS_ASSERT(!customers.any_over_limit());
    }

    void testAnyOverLimitFalse() {
        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "john@example.com");
        list<Charge> charges1;
        charges1.push_back(Charge("Store A", 50.0));
        charges1.push_back(Charge("Store B", 100.0));
        Customer customer1("1111", contact1, 1000.0, charges1);
        customers.insert(customer1);

        TS_ASSERT(!customers.any_over_limit());
    }

    void testAnyOverLimitTrue() {
        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "john@example.com");
        list<Charge> charges1;
        charges1.push_back(Charge("Store A", 800.0));
        charges1.push_back(Charge("Store B", 500.0));
        Customer customer1("1111", contact1, 1000.0, charges1);
        customers.insert(customer1);

        TS_ASSERT(customers.any_over_limit());
    }

    void testAnyOverLimitMultipleCustomers() {
        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "john@example.com");
        Contact contact2("Jane Smith", "456 Elm St", "jane@example.com");
        Contact contact3("Bob Brown", "789 Oak St", "bob@example.com");

        list<Charge> charges1;
        charges1.push_back(Charge("Store A", 100.0));
        Customer customer1("1111", contact1, 1000.0, charges1);

        list<Charge> charges2;
        charges2.push_back(Charge("Store B", 200.0));
        Customer customer2("2222", contact2, 2000.0, charges2);

        list<Charge> charges3;
        charges3.push_back(Charge("Store C", 3000.0));
        Customer customer3("3333", contact3, 2500.0, charges3);

        customers.insert(customer1);
        customers.insert(customer2);
        customers.insert(customer3);

        TS_ASSERT(customers.any_over_limit());
    }

    void testIncreaseLimitNotFound() {
        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "john@example.com");
        list<Charge> charges1;
        Customer customer1("1111", contact1, 1000.0, charges1);
        customers.insert(customer1);

        Customer* result = customers.increase_limit("9999", 500.0);
        TS_ASSERT_EQUALS(result, (Customer*)NULL);
    }

    void testIncreaseLimitFound() {
        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "john@example.com");
        list<Charge> charges1;
        Customer customer1("1111", contact1, 1000.0, charges1);
        customers.insert(customer1);

        customers.increase_limit("1111", 500.0);

        Contact temp_contact("", "", "");
        list<Charge> temp_charges;
        Customer temp("1111", temp_contact, 0.0, temp_charges);
        const Customer* found = customers.find(temp);

        TS_ASSERT_DIFFERS(found, (const Customer*)NULL);
        TS_ASSERT_EQUALS(found->GetLimit(), 1500.0);
    }

    void testIncreaseLimitMultipleTimes() {
        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "john@example.com");
        list<Charge> charges1;
        Customer customer1("1111", contact1, 1000.0, charges1);
        customers.insert(customer1);

        customers.increase_limit("1111", 500.0);
        customers.increase_limit("1111", 300.0);

        Contact temp_contact("", "", "");
        list<Charge> temp_charges;
        Customer temp("1111", temp_contact, 0.0, temp_charges);
        const Customer* found = customers.find(temp);

        TS_ASSERT_EQUALS(found->GetLimit(), 1800.0);
    }

    void testBinaryTreeToStringEmpty() {
        Customers<Customer> customers;
        std::string result = customers.to_string();
        TS_ASSERT(result.find("NULL") != std::string::npos);
    }

    void testBinaryTreeToStringWithData() {
        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "john@example.com");
        list<Charge> charges1;
        Customer customer1("1111", contact1, 1000.0, charges1);
        customers.insert(customer1);

        std::string result = customers.to_string();
        TS_ASSERT(result.length() > 0);
    }

    void testBinaryTreeToStringMultiple() {
        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "john@example.com");
        Contact contact2("Jane Smith", "456 Elm St", "jane@example.com");
        Contact contact3("Bob Brown", "789 Oak St", "bob@example.com");
        list<Charge> charges;
        Customer customer1("2222", contact1, 1000.0, charges);
        Customer customer2("1111", contact2, 1500.0, charges);
        Customer customer3("3333", contact3, 2000.0, charges);

        customers.insert(customer1);
        customers.insert(customer2);
        customers.insert(customer3);

        std::string result = customers.to_string();
        TS_ASSERT(result.length() > 0);
        TS_ASSERT(result.find("NULL") != std::string::npos);
    }

    void testBinaryTreeIsNull() {
        Customers<Customer> customers;
        TS_ASSERT(customers.is_null());

        Contact contact1("John Doe", "123 Main St", "john@example.com");
        list<Charge> charges1;
        Customer customer1("1111", contact1, 1000.0, charges1);
        customers.insert(customer1);

        TS_ASSERT(!customers.is_null());
    }

    void testBinaryTreeOutputOperator() {
        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "john@example.com");
        list<Charge> charges1;
        Customer customer1("1111", contact1, 1000.0, charges1);
        customers.insert(customer1);

        std::ostringstream oss;
        oss << customers;
        std::string result = oss.str();
        TS_ASSERT(result.length() > 0);
    }

    void testBTNodeToString() {
        Contact contact1("John Doe", "123 Main St", "john@example.com");
        list<Charge> charges1;
        Customer customer1("1111", contact1, 1000.0, charges1);
        BTNode<Customer> node(customer1);

        std::string result = node.to_string();
        TS_ASSERT(result.length() > 0);
    }

    void testBTNodeOutputOperator() {
        Contact contact1("John Doe", "123 Main St", "john@example.com");
        list<Charge> charges1;
        Customer customer1("1111", contact1, 1000.0, charges1);
        BTNode<Customer> node(customer1);

        std::ostringstream oss;
        oss << node;
        std::string result = oss.str();
        TS_ASSERT(result.length() > 0);
    }
};
#endif

