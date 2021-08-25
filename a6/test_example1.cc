#include "gtest/gtest.h"

extern "C" {
    #include "LinkedList_easy.h"
    #include "Hashtable_easy.h"
}

const char* first = "first";
const char* second="second";
const char* third = "third";
const char* fourth = "fourth";


TEST(TestLinkedList, CreateLinkedListNode) {
  char word[] = "hello";
  LinkedListNode* node = CreateLinkedListNode(word);
  EXPECT_EQ(node->payload, word);
}

TEST(TestLinkedList, CreateLinkedList) {
  LinkedList newList = CreateLinkedList();
  int num_elements = newList->num_elements;
  EXPECT_EQ(num_elements, 0);
}

TEST(TestLinkedList, InsertLinkedList) {
  LinkedList newList = CreateLinkedList();
  char word[] = "hello";
  InsertLinkedList(newList, word);
  int num_elements = newList->num_elements;
  EXPECT_EQ(num_elements, 1);
}

TEST(TestHashtable, CreateHashtable) {
  Hashtable ht = CreateHashtable(5);
  int num_buckets = ht->num_buckets;
  EXPECT_EQ(num_buckets, 5);
}

TEST(TestHashtable, SortWord) {
  char word[] = "cat";
  char* sortedword = SortWord(word);
  char correctword[] = "act";
  EXPECT_EQ(strcmp(correctword, sortedword), 0);
}

TEST(TestHashtable, GetFromHashtable) {
  Hashtable ht = CreateHashtable(5);
  HTKeyValuePtr kvp1 = (HTKeyValuePtr)malloc(sizeof(HTKeyValue));
  char word1[] = "abc";
  char word2[] = "bac";
  char word3[] = "act";
  char word4[] = "cat";
  kvp1->key = word1;
  kvp1->value = word1;
  ht = PutInHashtable(ht, kvp1);
  HTKeyValuePtr kvp2 = (HTKeyValuePtr)malloc(sizeof(HTKeyValue));
  kvp2->key = word1;
  kvp2->value = word2;
  ht = PutInHashtable(ht, kvp2);
  HTKeyValuePtr kvp3 = (HTKeyValuePtr)malloc(sizeof(HTKeyValue));
  kvp3->key = word3;
  kvp3->value = word4;
  ht = PutInHashtable(ht, kvp3);
  LinkedList anagramlist = GetFromHashtable(ht, kvp1->key);
  int num_elements = anagramlist->num_elements;
  EXPECT_EQ(num_elements, 2);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
