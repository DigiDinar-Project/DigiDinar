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
            "  },\n"
            "  {\n"
            "    \"height\": 3620,\n"
            "    \"1\": \"a030fe4185dd778c2a121e4d1a73f9bed024ae9a1184e62199ed5af0be1d92cac8fcdfecce9bbe6997a560fe4b54d383dd204fc3d2ab48c1bcda1eaa563d9e33d2cc7d95d1df2405e6bfe4c8ef6a66d7da2b2ecd9311690458a8b5ebd1b8a6fd23fe431d4a299a5e59d8c34f8006229e9f800c9780ec83432c8f63adc583a7c12b1aadd86d828913769d23f3dbd5b6e8fb0e26bfda6d161daf683983f992072ba2f828624e3a70cf300b739707dbe792bb5b6a2f7110ebfc80e1e674d501881cbad0a228bcde472d9a872186db496757e26a64836d500ccd2116cbbd769f492928af8cd0db9036e64a188245a25aca7c0baec17ca6c00384f5e7cd9d4ef6cc3a\",\n"
            "    \"5\": \"73ca8848f3955dee7c8ed471f10593d489ca908685584724b371cca79105908590a8c0b01beea8dbbfc91600ee4e0fcda209f0b1cd5ef38bd8ef64778de8bef49c4645e705d021f979a790df8f1ec08966209a04be71f5ac19764800cbe97422151e7dbfdd1a38f1f838839798e79d48e0593d3717073e3e59208e9ea34250d40b0aa3c309af777bf4d6abfce2ece03fff6d89538898fd05589c325708331488c82c18483eeaead4b6987c67318e5522c58abd7916ac319e7bcdc107c460bc07339ee2167dbfe8c4d2ffc1e228ac360c38de06540eb4660f6d3dc3bfed6ebc93428ff4e16146fa2ef40b6b467f3d644dd78d50377dbfbeb2639c771dd52b5851\",\n"
            "    \"10\": \"7761f48342fc479ade02007c7eff2e0271bfea218a6483a94559b962872cbd244a1406cc1eec4e31a4cf51e374f8cff598a7caeafa29c25672ff6306e683e4a7f05a3192baa34dd101e04278a22eb682d7d72012729ae1a10192b5dd71682264b172994a5494e5bacd49503b72509030752abc07b95118690de4a1126b688aca7b5c5eba7b79e3d3f3a5537c42aa96108d403297351d7c952c0cd8bc68b6ae03ed831561ce0fbeccb0bb543599a561614f5bfb96bc2ccf8b4b16533d13047c532d8fc3031d857bca496f251bdb60b6d31ff432e26d4de39c1a292769e0c6e87479b74ad97581b9a5432a597ecd5f208bc6ab803537f666698b25466ec6c78a1\",\n"
            "    \"50\": \"9192cd338294bc89f858c19087f455e28b476e9d77e732f5f9ba2bd85dc6d23f613bc37de64b01a15bcc3dce2b8eff5a2d196a7bdf5c1101f840971b2694af98252b89de28035e70db72bd236f60e298e81d04ffce65d55609881f7b2e402b1e45adb7999b014593df060cdf44bb3c70efda8e763a8a7f708883078d414ad09f5149460d1db5f7330f863ca70bb372f66f4a71fac9fe9bc40a75ce530a7d08cecd6b86b002c088ebb1aaec8156dcb286cf0cc2c1d0ddfdfc5ce2091201fece9a1e92ab6c9dd359b501fe741456efaff81da43c1a76d255c4e2787bfb6ab11f597aca0cf80ab3bafd84b3759189ad9913d0280bb252b58fbfcbb8f1c4d5046324\",\n"
            "    \"100\": \"c0215f0e26780183076c726d0c2e92450af16501200615c181f9ea412fca2c84353d24ceac52e65405d5cb6004291e1440672279b4aff3528e0e96f9b1dccaf879dfb236138049611bf5a6275c63a16a4e0773bb64dd4c648b221fcd2465a434332975237a568a1182cddb3aef30fa6f6a7def6712bd52c00622420b8409843179ce945200f3a6e5c474677848573e99228d3a5ed9e6ec42de51550156b161a9c8f61437e5d0102d2cd16cf255b68e26347ea381e55894b2e3edf099cf4ef46eb505220a01e4b150c5cc246bfb87adf9031979593054a608a7379cb7c86b0725068883f92fc15be1c5c9db4709801c0f412f7dcfe74301ea8742b5c332d6349b\",\n"
            "    \"500\": \"44f4df84e11c375d48c3e8f56546275f8b0fae526938e69e47ee44598962c678322808292864bfde8e9be06ef1edb5690abba07884d4733d269a36ad0130696cf5ec5cddfd105091dca3b4505a02ef376705f4908e29123e508525dd568b6479a31ae24d0495808311d53a46c5d85ecfbe10b72f7f03f819a5d2fbabff2c1ded8c0b685773b0c272b20cf6be0890be3369a6ad88c7aaa9c429be49eb6feec83dde386fb59a5fb9d283cfab8f212164041f978615b7ef5213a6dc9a244fd80ad9cef4efc23019ec7c29334c08dca7bc1297ccbde7b694f2581d636cb5a49dfca67c84713dfc02e56ee76a12d8908c33277d82982b9aa84fc90e6a1a8bfd844650\",\n"
            "    \"1000\": \"6698b2e627c3462115013ad642b3deadec66888389ce292a2a52a8cb1b07e7fa09fd7481d79fc13bfa89c24db4710ef99768041a092e6a4aa400800400888a13c705d49350afefc2546024301d32e8bc3c79eb66ba83f184a97911ce0224a474e9f9976fa955a3c2f59d8dd9bc3fe0ea8b67c6d3b0c7883ff9a0490ffeea25b773c63dec1b3f23265ddcd7e57cd40dad84b6095fd5aa9906a1b26f07bdb9f4f4675f85c3f89a90b46ec873cf4af0b24a05febc5cbf8937ad81a518a4a758c504cbdf37a6aac2ba92182a7d562df0070c1928e1771acd2fdadde4260b000a4fbc538eeae800b45e50ccf14c96d2b770aec08a761c1940c5444ad7f91317543092\",\n"
            "    \"5000\": \"a7525d00b9c3ebeca3d85a52d38156d36fef40ae052034e6c324da99f301e34648c5872e11a003af30455383d4b0124e69f209974304ce7d27bbee63840339532df6242a5980c66a9765a97b04a79c28737c50f3e6575dff4eac72a9cbcc96f808c6eed86177c923470afb24fe66fdd5bde41d8a321bd5092bbabdd448a980dc5337b5ac871663823220d893ad8bab208f576f70b7c987fd2754a03dff11052c4e5d6e75da47560647e1e7360e19fa417eec981bec3fbf02677491f024489d4d87b9e32329ddfa00446a27142a0732f5e242afabfc531ec77cc4b9756b27076224738f3d56f80963f535283f2b435eee20231f38265128fb8fed03a6d497071b\"\n"
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

#endif //DIGIDINAR_ACCUMULATORCHECKPOINTS_JSON_H
