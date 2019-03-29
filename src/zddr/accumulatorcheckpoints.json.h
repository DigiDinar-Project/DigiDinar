// Copyright (c) 2018 The PIVX developers
// Copyright (c) 2019 The DigiDinar developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DDR_ACCUMULATORCHECKPOINTS_JSON_H
#define DDR_ACCUMULATORCHECKPOINTS_JSON_H

#include <string>
std::string GetMainCheckpoints() {
    std::string strMainCheckpoints = "[\n"
            "  {\n"
                                     "    \"height\": 0,\n"
                                     "    \"1\": \"3c1\",\n"
                                     "    \"5\": \"3c1\",\n"
                                     "    \"10\": \"3c1\",\n"
                                     "    \"50\": \"3c1\",\n"
                                     "    \"100\": \"3c1\",\n"
                                     "    \"500\": \"3c1\",\n"
                                     "    \"1000\": \"3c1\",\n"
                                     "    \"5000\": \"3c1\"\n"
            "  },\n"
            "  {\n"
            "    \"height\": 120,\n"
            "    \"1\": \"91d320ca52136dd6cc0047f63fe411c295e77c1e41be017cd9c3ef4fa12239a6473c09ceb45fc62570a709f241d5e5395945f4a2855db0198a1148101afb6d7d608f18879f4c02c2326f86e9aa9bb6f009b400fa04e3c14f3bc4077365b11621f14b86a52cd700c4884ba1d3eae1167d0afc86c6b5df819278eb7130fb1fa91e6736960412db5e5a9c7ce7f5fa1b61c9359ec76d08240cf941749e7d2d56cc6f70a66896a9d2e9e408181acbba23f03dda1fc677f739f2d9e953883483cfd76b7263e339338a9df70f3d42925cfbe0c1620201e9c1790a0744cacfe4b202492bbc46cf18c2b9acc333a0fa1bd1963cfedf5bf387fa5bb614be8a6cb994e8f74e\",\n"
            "    \"5\": \"3267af51fc4c1c7a82e3b9f86c9657b19fb24639d2c363f40378b9447488d5645f5b83f5088a8669e78d6133b44aab8b59decbcb6cd55ced95dfc972f82815b28216892c58b003058356b1ad91c10280dc64eeb93a5644dd82ada39b7a37f2b25a3ae35febb47763b961f4d2b7d2b74a120dd70d2aa16559dd8bd82d4a1233e53cf7ef874ec4ad5d64fd44bf29555c04b6a7e4b09cde80c7b8646bea4cb2895187ea1e65f04628ab24e5d4887f2db0d6e72dec675bc3646e34dfaff50612271176d41d87d1f42dce76d6ae31cf3bb531cf9c0cd294ca67567c3f4f394753c7d49d6cc0dfef85e272f25d40a157013205674846a9dffbab099c1c356c1d0d2aa8\",\n"
            "    \"10\": \"51f37b4778a257f63e77dda53ede6e9442db9ac504c93051fc919a0f0d58f179a96d109a1a678154bbdf2c5bef5612e69d8e8ae74eea9da76291677ed2e007251fbd6dd6c5183454f758491a1d826515a99d506ab763a06afc74d8c97f5a470b370e5c2289057d7bb682f634386cd2112325362582859333904d429a0900ea965cf2830cc330e3255c080127cf463fffa74808dfa24843cba0e182befa5379f45d2834986f4a7d4459748b601488f557197c1ff3b9478b6e2317508036879d48566f95873c8708b847cf4e6f97c2df16b063456f1022e78a8dbe99c4818155c0e802e7a593b67d200bea77f50caf9929bcd5c958bcc7316db4feb9c7a2d133e8\",\n"
            "    \"50\": \"956c1e1cde5352447eb0da86aefb643eee3262966f428460e25dba61a968f37242f27a6f517171d17025fea432d865615683445f4f4ac64d70d30a0643abcc46c1760efd828e0f894c976756592026fae1bbcbf506831703bfdac3d8e60a305574d0109c2f5416318970fccaf166d92c9551ce94012176fac04ad551dc23e35a3786908756f28e9cd0fbce9dfcc9e41074b66bbb2ef59c6cdfd016f84a2da70a5afac37416264969d9211a5ce9643accbcb9361532e7bd0a474630bdb6082bde4832b2946214026095754e224667fde467f0e363b239b76d098b35aea1e34155a049f6aa88704593411fee7eb3bf05564519a1db5797a0739ff1db3251b7c8e\",\n"
            "    \"100\": \"3c1\",\n"
            "    \"500\": \"3c1\",\n"
            "    \"1000\": \"3c1\",\n"
            "    \"5000\": \"3c1\"\n"
            "  }\n"
            "]";
    return strMainCheckpoints;
}

std::string GetTestCheckpoints() {
    std::string strTestCheckpoints = "[\n"
            "  {\n"
                                     "    \"height\": 0,\n"
                                     "    \"1\": \"0\",\n"
                                     "    \"5\": \"0\",\n"
                                     "    \"10\": \"0\",\n"
                                     "    \"50\": \"0\",\n"
                                     "    \"100\": \"0\",\n"
                                     "    \"500\": \"0\",\n"
                                     "    \"1000\": \"0\",\n"
                                     "    \"5000\": \"0\"\n"
            "  }\n"
            "]";
    return strTestCheckpoints;
}

std::string GetRegTestCheckpoints() {
    std::string strRegTestCheckpoints = "[\n"
            "  {\n"
            "    \"height\": 0,\n"
            "    \"1\": \"0\",\n"
            "    \"5\": \"0\",\n"
            "    \"10\": \"0\",\n"
            "    \"50\": \"0\",\n"
            "    \"100\": \"0\",\n"
            "    \"500\": \"0\",\n"
            "    \"1000\": \"0\",\n"
            "    \"5000\": \"0\"\n"
            "  }\n"
            "]";
    return strRegTestCheckpoints;
}

#endif //DDR_ACCUMULATORCHECKPOINTS_JSON_H
