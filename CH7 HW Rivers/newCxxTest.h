    //copyright 2025

    #include <cxxtest/TestSuite.h>
    #include "Rivers.h"
    #include <list>

    class RiversTestSuite : public CxxTest::TestSuite {
    public:
        void testDefaultConstructor() {
            Rivers r;
            TS_ASSERT_EQUALS(r.getRiverName(), "");
            TS_ASSERT_EQUALS(r.getPh(), 0.0);
            TS_ASSERT_EQUALS(r.getDo(), 0.0);
            TS_ASSERT(r.getRivers().empty());
        }

        void testConstructor() {
            std::list<Rivers*> rs;
            Rivers r("Test", 7.0, 6.5, rs);
            TS_ASSERT_EQUALS(r.getRiverName(), "Test");
            TS_ASSERT_EQUALS(r.getPh(), 7.0);
            TS_ASSERT_EQUALS(r.getDo(), 6.5);
        }

        void testSetters() {
            std::list<Rivers*> rs;
            Rivers r("Test", 7.0, 6.5, rs);
            r.setRiverName("NewName");
            r.setPh(8.0);
            r.setDo(7.0);
            TS_ASSERT_EQUALS(r.getRiverName(), "NewName");
            TS_ASSERT_EQUALS(r.getPh(), 8.0);
            TS_ASSERT_EQUALS(r.getDo(), 7.0);
        }

        void testMakeRiver() {
            std::list<Rivers*> rs1;
            Rivers* r1 = new Rivers("Main", 7.0, 6.5, rs1);
            std::list<Rivers*> rs2;
            Rivers* r2 = new Rivers("Trib", 6.0, 6.0, rs2);
            r1->make_river(r2);
            TS_ASSERT_EQUALS(r1->getRivers().size(), 1);
            delete r1;
        }

        void testSetAcidLevel() {
            Rivers::setAcidLevel(6.0);
            std::list<Rivers*> rs;
            Rivers r("Test", 5.5, 6.5, rs);
            TS_ASSERT(r.list_acidic_rivers().find("Test") != std::string::npos);
        }

        void testListAcidicRivers() {
            std::list<Rivers*> rs1;
            Rivers* r1 = new Rivers("Main", 7.0, 6.5, rs1);
            std::list<Rivers*> rs2;
            Rivers* r2 = new Rivers("Acidic", 6.0, 6.0, rs2);
            r1->make_river(r2);
            Rivers::setAcidLevel(6.5);
            std::string result = r1->list_acidic_rivers();
            TS_ASSERT(result.find("Acidic") != std::string::npos);
        }

        void testListAcidicRiversMultiple() {
            std::list<Rivers*> rs1;
            Rivers* r1 = new Rivers("Main", 7.0, 6.5, rs1);
            std::list<Rivers*> rs2;
            Rivers* r2 = new Rivers("Acidic1", 6.0, 6.0, rs2);
            std::list<Rivers*> rs3;
            Rivers* r3 = new Rivers("Acidic2", 5.5, 6.0, rs3);
            r1->make_river(r2);
            r1->make_river(r3);
            Rivers::setAcidLevel(6.5);
            std::string result = r1->list_acidic_rivers();
            TS_ASSERT(result.find("Acidic1") != std::string::npos);
            TS_ASSERT(result.find("Acidic2") != std::string::npos);
        }

        void testUnhealthyLowPH() {
            std::list<Rivers*> rs;
            Rivers* r = new Rivers("Test", 6.0, 6.5, rs);
            TS_ASSERT(r->unhealthy());
        }

        void testUnhealthyHighPH() {
            std::list<Rivers*> rs;
            Rivers* r = new Rivers("Test", 9.0, 6.5, rs);
            TS_ASSERT(r->unhealthy());
        }

        void testUnhealthyLowDO() {
            std::list<Rivers*> rs;
            Rivers* r = new Rivers("Test", 7.0, 5.0, rs);
            TS_ASSERT(r->unhealthy());
        }

        void testHealthy() {
            std::list<Rivers*> rs;
            Rivers* r = new Rivers("Test", 7.0, 6.5, rs);
            TS_ASSERT(!r->unhealthy());
        }

        void testUnhealthyTributary() {
            std::list<Rivers*> rs1;
            Rivers* r1 = new Rivers("Main", 7.0, 6.5, rs1);
            std::list<Rivers*> rs2;
            Rivers* r2 = new Rivers("Bad", 6.0, 6.5, rs2);
            r1->make_river(r2);
            TS_ASSERT(r1->unhealthy());
        }

        void testUnhealthyWithMultipleTributaries() {
            std::list<Rivers*> rs1;
            Rivers* r1 = new Rivers("Main", 7.0, 6.5, rs1);
            std::list<Rivers*> rs2;
            Rivers* r2 = new Rivers("Good", 7.0, 6.5, rs2);
            std::list<Rivers*> rs3;
            Rivers* r3 = new Rivers("Bad", 6.0, 6.5, rs3);
            r1->make_river(r2);
            r1->make_river(r3);
            TS_ASSERT(r1->unhealthy());
        }

        void testLowerAllPH() {
            std::list<Rivers*> rs1;
            Rivers* r1 = new Rivers("Main", 7.0, 6.5, rs1);
            std::list<Rivers*> rs2;
            Rivers* r2 = new Rivers("Trib", 6.5, 6.0, rs2);
            r1->make_river(r2);
            Rivers* r3 = r1->lower_all_ph();
            TS_ASSERT_EQUALS(r3->getPh(), 6.9);
            TS_ASSERT_EQUALS(r3->getRivers().front()->getPh(), 6.4);
        }

        void testLowerAllPHOverload() {
            std::list<Rivers*> rs1;
            Rivers* r1 = new Rivers("Test", 7.0, 6.5, rs1);
            std::list<Rivers*> rs2;
            Rivers* r2 = new Rivers("Trib", 8.0, 7.0, rs2);
            Rivers* r3 = r1->lower_all_ph(r2, nullptr);
            TS_ASSERT_EQUALS(r3->getPh(), 7.9);
        }

        void testFindSubsystemRoot() {
            std::list<Rivers*> rs;
            Rivers* r = new Rivers("Main", 7.0, 6.5, rs);
            Rivers* found = r->find_subsystem("Main");
            TS_ASSERT_EQUALS(found, r);
        }

        void testFindSubsystemTributary() {
            std::list<Rivers*> rs1;
            Rivers* r1 = new Rivers("Main", 7.0, 6.5, rs1);
            std::list<Rivers*> rs2;
            Rivers* r2 = new Rivers("Trib", 6.5, 6.0, rs2);
            r1->make_river(r2);
            Rivers* found = r1->find_subsystem("Trib");
            TS_ASSERT_EQUALS(found, r2);
        }

        void testFindSubsystemNotFound() {
            std::list<Rivers*> rs;
            Rivers* r = new Rivers("Main", 7.0, 6.5, rs);
            Rivers* found = r->find_subsystem("NotThere");
            TS_ASSERT_EQUALS(found, nullptr);

        }

        void testFindSubsystemOverload() {
            std::list<Rivers*> rs1;
            Rivers* r1 = new Rivers("Main", 7.0, 6.5, rs1);
            std::list<Rivers*> rs2;
            Rivers* r2 = new Rivers("Test", 7.0, 6.5, rs2);
            Rivers* found = r1->find_subsystem(r2, "Test");
            TS_ASSERT_EQUALS(found, r2);
        }

        void testPrint() {
            std::list<Rivers*> rs;
            Rivers* r1 = new Rivers("Test", 7.0, 6.5, rs);
            Rivers* r2 = new Rivers("Test", 7.0, 6.5, rs);
            Rivers* r3 = new Rivers("Test", 7.0, 6.5, rs);
            Rivers::find_subsystem();

            r1->print(rs, 1);
        }

        void testPrintOverload() {
            std::list<Rivers*> rs1;
            Rivers* r1 = new Rivers("Main", 7.0, 6.5, rs1);
            std::list<Rivers*> rs2;
            Rivers* r2 = new Rivers("Test", 7.0, 6.5, rs2);
            r1->print(r2, 0);
        }

        void testListAcidicRiversOverload() {
            std::list<Rivers*> rs1;
            Rivers* r1 = new Rivers("Main", 7.0, 6.5, rs1);
            std::list<Rivers*> rs2;
            Rivers* r2 = new Rivers("Acidic", 6.0, 6.0, rs2);
            Rivers::setAcidLevel(6.5);
            std::string result = r1->list_acidic_rivers(r2);
            TS_ASSERT(!result.find("Acidic"));
        }

        void testUnhealthyOverload() {
            std::list<Rivers*> rs1;
            Rivers* r1 = new Rivers("Main", 7.0, 6.5, rs1);
            std::list<Rivers*> rs2;
            Rivers* r2 = new Rivers("Bad", 6.0, 6.5, rs2);
            TS_ASSERT(r1->unhealthy(r2));
        }

        void testBadNumbersHelper() {
            std::list<Rivers*> rs1;
            Rivers* r1 = new Rivers("Main", 7.0, 6.5, rs1);
            std::list<Rivers*> rs2;
            Rivers* r2 = new Rivers("Bad", 6.0, 6.5, rs2);
            TS_ASSERT(r1->bad_numbers(r2));
        }

        void testBadNumbersNullHelper() {
            std::list<Rivers*> rs;
            Rivers* r = new Rivers("Main", 7.0, 6.5, rs);
            TS_ASSERT(!r->bad_numbers(nullptr));
        }

        void testSetRivers() {
            std::list<Rivers*> rs1;
            Rivers* r1 = new Rivers("Main", 7.0, 6.5, rs1);
            std::list<Rivers*> rs2;
            Rivers* r2 = new Rivers("Trib", 6.5, 6.0, rs2);
            std::list<Rivers*> newList;
            newList.push_back(r2);
            r1->setRivers(newList);
            TS_ASSERT_EQUALS(r1->getRivers().size(), 1);
        }

        void testListAcidicTributaries() {
            std::list<Rivers*> rs1;
            Rivers* r1 = new Rivers("Main", 7.0, 6.5, rs1);
            std::list<Rivers*> rs2;
            Rivers* r2 = new Rivers("Acidic", 6.0, 6.0, rs2);
            r1->make_river(r2);
            Rivers::setAcidLevel(6.5);
            std::string result = r1->list_acidic_tributaries(r1->getRivers().begin(), r1->getRivers().end());
            TS_ASSERT(!result.find("Acidic"));
        }

        void testUnhealthyTrib() {
            std::list<Rivers*> rs1;
            Rivers* r1 = new Rivers("Main", 7.0, 6.5, rs1);
            std::list<Rivers*> rs2;
            Rivers* r2 = new Rivers("Bad", 6.0, 6.5, rs2);
            r1->make_river(r2);
            TS_ASSERT(r1->unhealthy_trib(r1->getRivers().begin(), r1->getRivers().end()));
        }

        void testUpdatePh() {
            std::list<Rivers*> rs1;
            Rivers* r1 = new Rivers("Main", 7.0, 6.5, rs1);
            std::list<Rivers*> rs2;
            Rivers* r2 = new Rivers("Trib", 6.5, 6.0, rs2);
            r1->make_river(r2);
            std::list<Rivers*> newList;
            std::list<Rivers*> result = r1->update_ph(r1->getRivers().begin(), r1->getRivers().end(), newList);
            TS_ASSERT_EQUALS(result.size(), 1);
            TS_ASSERT_EQUALS(result.front()->getPh(), 6.4);
        }

        void testFindInList() {
            std::list<Rivers*> rs1;
            Rivers* r1 = new Rivers("Main", 7.0, 6.5, rs1);
            std::list<Rivers*> rs2;
            Rivers* r2 = new Rivers("Target", 6.5, 6.0, rs2);
            r1->make_river(r2);
            Rivers* found = r1->find_in_list(r1->getRivers().begin(), r1->getRivers().end(), "Target");
            TS_ASSERT_EQUALS(found, r2);
        }

        void testPrintIterator() {
            std::list<Rivers*> rs1;
            Rivers* r1 = new Rivers("Main", 7.0, 6.5, rs1);
            std::list<Rivers*> rs2;
            Rivers* r2 = new Rivers("Trib", 6.5, 6.0, rs2);
            r1->make_river(r2);
            r1->print(r1->getRivers().begin(), r1->getRivers().end(), 1);
        }
    };
