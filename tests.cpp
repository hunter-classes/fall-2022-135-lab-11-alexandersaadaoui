#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"
#include <string>

TEST_CASE("A") {
    Profile p1("towardspeace", "Megatron");
    CHECK(p1.getUsername() == "towardspeace");
    CHECK(p1.getFullName() == "Megatron (@towardspeace)");
    p1.setDisplayName("Decepticon Megatron");
    CHECK(p1.getUsername() == "towardspeace");
    CHECK(p1.getFullName() == "Decepticon Megatron (@towardspeace)");

    Profile p2("aircommander", "Starscream");
    CHECK(p2.getUsername() == "aircommander");
    CHECK(p2.getFullName() == "Starscream (@aircommander)");
    p2.setDisplayName("Decepticon Starscream");
    CHECK(p2.getFullName() == "Decepticon Starscream (@aircommander)");
}

TEST_CASE("B") {
    Network nw;
    CHECK(nw.addUser("megatron", "Megatron") == 1);
    CHECK(nw.addUser("starscream", "Starscream") == 1);
    CHECK(nw.addUser("optimus..", "Optimus") == 0);
    CHECK(nw.addUser("bumblebee 3", "Bumblebee") == 0);
    CHECK(nw.addUser("sound-wave", "Soundwave") == 0);
    CHECK(nw.addUser("!shockwave", "Shockwave") == 0);

    for(int i = 2; i < 20; i++)
    {
        std::cout << nw.addUser("megatron" + std::to_string(i), 
        "Megatron" + std::to_string(i)) << std::endl;   
    }
    CHECK(nw.addUser("megatron1984", "Megatron") == 0); 
}

TEST_CASE("C") {
    Network nw2;
    nw2.addUser("megatron", "Megatron");
    nw2.addUser("starscream", "Starscream");
    nw2.addUser("optimus", "Optimus");
    nw2.addUser("bumblebee", "Bumblebee");

    CHECK(nw2.follow("megatron", "starscream") == true);
    CHECK(nw2.follow("megatron", "optimus") == true);
    CHECK(nw2.follow("soundwave", "megatron") == false);
    CHECK(nw2.follow("optimus", "shockwave") == false);
}