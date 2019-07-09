// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2018 The PIVX developers
// Copyright (c) 2019-2019 The DigiDinar developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (0, uint256("0000099ee5abb388a0fa2ca1864cfee1cbe510ab0e9abacfed70c7a3d6d9203e"))
    (630, uint256("9cf5b61600a1d8489b7295be8a12984104f533d2e0856ef00745168456eff215"))
    (7728, uint256("bb1f0cd26f221e47effdedce06dbeeac8ab9692fee2ee3f83356ef5933fefac4"))
    (58009, uint256("5444275d87e9eea98a743aec96589e19b82e15578faf18082a6edf8b31b06ffe"))
    ;
static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1562704723, // * UNIX timestamp of last checkpoint block
    116286,          // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1740710,
    0,
    250};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1454124731,
    0,
    100};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params(bool useModulusV1) const
{
    assert(this);
    static CBigNum bnHexModulus = 0;
    if (!bnHexModulus)
        bnHexModulus.SetHex(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsHex = libzerocoin::ZerocoinParams(bnHexModulus);
    static CBigNum bnDecModulus = 0;
    if (!bnDecModulus)
        bnDecModulus.SetDec(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsDec = libzerocoin::ZerocoinParams(bnDecModulus);

    if (useModulusV1)
        return &ZCParamsHex;

    return &ZCParamsDec;
}

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x91;
        pchMessageStart[1] = 0xc5;
        pchMessageStart[2] = 0xfd;
        pchMessageStart[3] = 0xe9;
        vAlertPubKey = ParseHex("04b05761185420f9f5d0d3e213352b6cc95e2da8eefd4f67321a0c58855d96ccb29b6b2e0cfba7e60bab83ddc30ce3506d001708d4b89b450500bd95828990f571");
        nDefaultPort = 32001;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // Digi Dinar starting difficulty is 1 / 2^12
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 75; // 75%
        nRejectBlockOutdatedMajority = 95; // 95%
        nToCheckBlockUpgradeMajority = 100; // Approximate expected amount of blocks in 7 days (1440*7.5)
        

        nMinerThreads = 0;
        nTargetSpacing = 1 * 60;  // Digi Dinar: 1 minute
        nMaturity = 100;
        nMaxMoneyOut = 120000000 * COIN;

        nMasternodeCollateral = 25000;
        strDevFeeAddress = "D5wVvyFg9t3TQGszyAkQ3G11QPJoS6Ldm3";
        nStakeInputMinimal = 6 * COIN;

        /** Height or Time Based Activations **/
        nLastPOWBlock = 300;
        nModifierUpdateBlock = 0;
        nZerocoinStartHeight = 0;
        nZerocoinStartTime = 1550792244; // Genesis time
        nBlockZerocoinV2 = 20;

        // Public coin spend enforcement
        nPublicZCSpends = 58700;

        // Fake Serial Attack
        nFakeSerialBlockheightEnd = -1;
        nSupplyBeforeFakeSerial = 0;   // zerocoin supply at block nFakeSerialBlockheightEnd

        /**
         * Build the genesis block. Note that the output of the genesis coinbase cannot
         * be spent as it did not originally exist in the database.
         *
         * CBlock(hash=00000ffd590b14, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=e0028e, nTime=1390095618, nBits=1e0ffff0, nNonce=28917698, vtx=1)
         *   CTransaction(hash=e0028e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
         *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d01044c5957697265642030392f4a616e2f3230313420546865204772616e64204578706572696d656e7420476f6573204c6976653a204f76657273746f636b2e636f6d204973204e6f7720416363657074696e6720426974636f696e73)
         *     CTxOut(nValue=50.00000000, scriptPubKey=0xA9037BAC7050C479B121CF)
         *   vMerkleTree: e0028e
         */
        const char* pszTimestamp = "Internet literacy must become universal within the Arab world.";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 0 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04870b8a9e2339021a1830d1f7f4b3ead77c8a62a3df36e55d96589bee35cdf9ca5719160669892536d7298e25dc892106c1786f8aefa72151799f86e4214686fc") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 5;
        genesis.nTime = 1550792244;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 2868175;
        
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x0000099ee5abb388a0fa2ca1864cfee1cbe510ab0e9abacfed70c7a3d6d9203e"));
        assert(genesis.hashMerkleRoot == uint256("0x355339996acc666194e66c4e7f0b151d3eef1ae7154970587f3a3295aab56a19"));

        vSeeds.push_back(CDNSSeedData("134.255.234.59", "134.255.234.59"));     // Primary DNS Seeder
        vSeeds.push_back(CDNSSeedData("134.255.216.244", "134.255.216.244"));     // Primary DNS Seeder
        vSeeds.push_back(CDNSSeedData("92.42.46.121", "92.42.46.121"));     // Primary DNS Seeder
        
        // Digi Dinar addresses start with 'D'
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 30);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 13);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 128+30);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2D)(0x25)(0x33).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x31)(0x2B).convert_to_container<std::vector<unsigned char> >();
        // 	BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x77).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        nBudgetCycleBlocks = 43200; //!< Amount of blocks in a months period of time (using 1 minutes per) = (60*24*30)
        strSporkKey = "047639742517259eca25085a46d37699beac997a7ae0e7f73c36f51919a538041ce5be3c528a9defa5213bfa228958f95ba2770947cc9b3483d73f4fd6d1b97589";
        strObfuscationPoolDummyAddress = "D87q2gC9j6nNrnzCsg4aY6bHMLsT9nUhEw";
        nStartMasternodePayments = 1547119800; //Wed, 25 Jun 2014 20:36:16 GMT

        /** Zerocoin */
        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
            "31438167899885040445364023527381951378636564391212010397122822120720357";
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMaxZerocoinPublicSpendsPerTransaction = 637; // Assume about 220 bytes each input
        nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 1;
        nDefaultSecurityLevel = 100; //full security level for accumulators
        nZerocoinHeaderVersion = 5; //Block headers must be this version once zerocoin is active
        nZerocoinRequiredStakeDepth = 200; //The required confirmations for a zddr to be stakable

        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee
        nProposalEstablishmentTime = 60 * 60 * 24; // Proposals must be at least a day old to make it into a budget
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
    
    
    CAmount StakeInputMinimal(int nTargetHeight) const
    {
        if (nTargetHeight < 60000 )
            return nStakeInputMinimal; 
        else if (nTargetHeight < 150000 )
            return nStakeInputMinimal * 30; 
        else
            return nStakeInputMinimal * 60;
    }
    
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x46;
        pchMessageStart[1] = 0x76;
        pchMessageStart[2] = 0x65;
        pchMessageStart[3] = 0xba;
        vAlertPubKey = ParseHex("049930cddd1436108f3d1f7d770277181fcd858d7253a74302f9dccb1eb940e55a163ab373d744df18471c1b632a048c390118c5ad257d5bba41200274a606a6e8");
        nDefaultPort = 42001;
        nMinerThreads = 0;
        nTargetSpacing = 1 * 60;  // Digi Dinar: 1 minute
        nLastPOWBlock = 200;
        nMaturity = 100;
        nModifierUpdateBlock = 0;
        nMaxMoneyOut = 120000000 * COIN;
        nZerocoinStartHeight = 15;
        nZerocoinStartTime = 1550792244;
        nBlockZerocoinV2 = 15;

        // Public coin spend enforcement
        nPublicZCSpends = 0;

        nSubsidyHalvingBlock = 1600;
        nMasternodeCollateral = 25000;
        nStakeInputMinimal = 50 * COIN;

        // Fake Serial Attack
        nFakeSerialBlockheightEnd = -1;
        nSupplyBeforeFakeSerial = 0;

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1547119740;
        genesis.nNonce = 2908155;
        
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00000df3a564340ff158d6cc1190fe85ded6c129b3478a3e687cca4ff9e91fda"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 98); // Testnet digidinar addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet digidinar script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 128+98);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
	nBudgetCycleBlocks = 144; //!< Ten cycles per day on testnet
        
        strSporkKey = "042f3ee3fd6b795c7176f61e967fd7923d4c43f09d68720dfc05239f64b4765471f9a0049e1508f663c13bb454706e73947fae169c0ea41ddb6a97c4fa5b38690e";
        strObfuscationPoolDummyAddress = "y57cqfGRkekRyDRNeJiLtYVEbvhXrNbmox";
        nStartMasternodePayments = 1547119740 + 500 * 120; 
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                       // here because we only have a 8 block finalization window on testnet
        nProposalEstablishmentTime = 60 * 5; // Proposals must be at least 5 mns old to make it into a test budget
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
    
    CAmount StakeInputMinimal(int nTargetHeight) const
    {
        if (nTargetHeight < 6000 )
            return nStakeInputMinimal; 
        else
            return nStakeInputMinimal * 30;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xa2;
        pchMessageStart[1] = 0xcf;
        pchMessageStart[2] = 0x7e;
        pchMessageStart[3] = 0xac;
        nMinerThreads = 1;
        nTargetSpacing = 1 * 60;
        nDefaultPort = 43001;
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1547119739;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 12345;

        // Fake Serial Attack
        nFakeSerialBlockheightEnd = -1;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x7ca3e82de950df19c22b5391ec18d16ffa3d2ba77bf5ee130324ba181d59d66b"));

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fSkipProofOfWorkCheck = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
    
    CAmount StakeInputMinimal(int nTargetHeight) const
    {
        if (nTargetHeight < 6000)
            return nStakeInputMinimal; 
        else
            return nStakeInputMinimal * 30;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 17417;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingBlock(int anSubsidyHalvingBlock) { nSubsidyHalvingBlock = anSubsidyHalvingBlock; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
