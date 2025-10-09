#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
#include "Customers.h"
#include "Customer.h"
#include "Contact.h"
#include "Charge.h"
#include <list>

class newCxxTest : public CxxTest::TestSuite {
public:

    void testCountBigLimits() {
        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "john.doe@example.com");
        Contact contact2("Jane Smith", "456 Elm St", "jane.smith@example.com");

        list<Charge> charges1;
        charges1.push_back(Charge("Store A", 50.0));
        Customer customer1("1111", contact1, 1000.0, charges1);

        list<Charge> charges2;
        charges2.push_back(Charge("Store B", 200.0));
        Customer customer2("2222", contact2, 2500.0, charges2);

        customers.insert(customer1);
        customers.insert(customer2);

        TS_ASSERT_EQUALS(customers.count_big_limits(1500.0), 1);
        TS_ASSERT_EQUALS(customers.count_big_limits(500.0), 2);
        TS_ASSERT_EQUALS(customers.count_big_limits(3000.0), 0);
    }

    void testAnyOverLimit() {
        Customers<Customer> customers_over;
        Contact contact1("John Doe", "123 Main St", "john.doe@example.com");

        list<Charge> charges1;
        charges1.push_back(Charge("Store A", 1500.0));
        Customer customer1("1111", contact1, 1000.0, charges1);
        customers_over.insert(customer1);

        TS_ASSERT(customers_over.any_over_limit());

        Customers<Customer> customers_under;
        Contact contact2("Jane Smith", "456 Elm St", "jane.smith@example.com");
        list<Charge> charges2;
        charges2.push_back(Charge("Store B", 200.0));
        Customer customer2("2222", contact2, 2500.0, charges2);
        customers_under.insert(customer2);

        TS_ASSERT(!customers_under.any_over_limit());
    }

    void testIncreaseLimit() {
        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "john.doe@example.com");
        list<Charge> charges1;
        Customer customer1("1111", contact1, 1000.0, charges1);
        customers.insert(customer1);

        customers.increase_limit("1111", 500.0);

        const Customer* found_customer = customers.find("1111");

        TS_ASSERT_DIFFERS(found_customer, (const Customer*)NULL);
        if (found_customer) {
            TS_ASSERT_EQUALS(found_customer->GetLimit(), 1500.0);
        }
    }
};
#endif /* NEWCXXTEST_H */