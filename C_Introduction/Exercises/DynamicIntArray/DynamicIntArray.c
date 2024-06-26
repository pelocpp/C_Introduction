// =====================================================================================
// DynamicIntArray.c
// =====================================================================================

#include <stdio.h>

#include "DynamicintArray.h"

// =====================================================================================

int initDynamicIntArray(struct DynamicIntArray* da, size_t length)
{
    int* tmp = (int*) calloc(length, sizeof(int));
    if (tmp == NULL) {
        printf("initDynamicIntArray: Out of memory");
        return 0;
    }

    da->m_data = tmp;
    da->m_length = length;
    return 1;
}

void releaseDynamicIntArray(struct DynamicIntArray* da)
{
    if (da->m_data != NULL) {

        free(da->m_data);

        da->m_data = NULL;
        da->m_length = 0;
    }
}

void createDynamicIntArrayFromArray(struct DynamicIntArray* array, int* values, int length)
{
    array->m_data = (int*) malloc(sizeof(int) * length);
    if (array->m_data == (int*)0) {
        return;
    }

    for (int i = 0; i < length; i++) {
        array->m_data[i] = values[i];
    }

    array->m_length = length;
}

void createDynamicIntArrayFromDynamicIntArray(struct DynamicIntArray* array, struct DynamicIntArray* other)
{
    array->m_data = (int*) malloc(sizeof(int) * other->m_length);
    if (array->m_data == (int*)0) {
        printf("Out of memory");
        return;
    }

    for (int i = 0; i < other->m_length; i++) {
        array->m_data[i] = other->m_data[i];
    }

    array->m_length = other->m_length;
}

void fillDynamicIntArray(struct DynamicIntArray* array, int value)
{
    for (int i = 0; i < array->m_length; i++) {
        array->m_data[i] = value;
    }
}

size_t getLength(struct DynamicIntArray* array)
{
    return array->m_length;
}

int get(struct DynamicIntArray* array, int index)
{
    if (index < array->m_length) {
        return array->m_data[index];
    }
    else {
        printf("Wrong Index: %d [Length = %zu]\n", index, array->m_length);
        return -1;
    }
}

void set(struct DynamicIntArray* array, int index, int value)
{
    if (index < array->m_length) {
        array->m_data[index] = value;
    }
    else {
        printf("Wrong Index: %d [Length = %zu]\n", index, array->m_length);
    }
}

int resizeDynamicIntArray(struct DynamicIntArray* array, int newLength)
{
    if (newLength <= array->m_length)
    {
        // just shorten length, keep buffer
        array->m_length = newLength;

        return 1;
    }
    else {

        // allocate new (temporary) buffer
        int* tmp = (int*) calloc(newLength, sizeof(int));
        if (tmp == NULL) {
            printf("initDynamicIntArray: Out of memory");
            return 0;
        }
        else {

            // copy current buffer into new one
            for (size_t i = 0; i < array->m_length; ++i) {
                tmp[i] = array->m_data[i];
            }

            // initialize rest of buffer with default values
            for (size_t i = array->m_length; i < newLength; ++i) {
                tmp[i] = 0;
            }

            // release current buffer
            free(array->m_data);

            // switch to new buffer
            array->m_data = tmp;
            array->m_length = newLength;

            return 1;
        }
    }
}

int shrinkToFitDynamicIntArray(struct DynamicIntArray* array)
{
    // // allocate new - temporary and fitting - buffer
    int* tmp = (int*) calloc(array->m_length, sizeof(int));
    if (tmp == NULL) {
        printf("shrinkToFitDynamicIntArray: Out of memory");
        return 0;
    }
    else {

        // copy current buffer into new one
        for (size_t i = 0; i < array->m_length; ++i) {
            tmp[i] = array->m_data[i];
        }

        // release current buffer
        free(array->m_data);

        // switch to new buffer
        array->m_data = tmp;

        return 1;
    }
}

int minimum(struct DynamicIntArray* array)
{
    if (array->m_length == 0) {
        return 0;
    }

    int min = array->m_data[0];

    for (int i = 1; i < array->m_length; i++) {
        if (min > array->m_data[i]) {
            min = array->m_data[i];
        }
    }

    return min;
}

int maximum(struct DynamicIntArray* array)
{
    if (array->m_length == 0) {
        return 0;
    }

    int max = array->m_data[0];

    for (int i = 1; i < array->m_length; i++) {
        if (max < array->m_data[i]) {
            max = array->m_data[i];
        }
    }

    return max;
}

int indexOf(struct DynamicIntArray* array, int value)
{
    // perform a linear search
    for (int i = 0; i < array->m_length; i++) {
        if (array->m_data[i] == value) {
            return i;
        }
    }

    return -1;
}

int equalsDynamicIntArray(struct DynamicIntArray* array, struct DynamicIntArray* other)
{
    if (array->m_length != other->m_length) {
        return 0;
    }

    for (int i = 0; i < array->m_length; i++) {
        if (array->m_data[i] != other->m_data[i]) {
            return 0;
        }
    }

    return 1;
}

int containsDynamicIntArray(struct DynamicIntArray* array, int value)
{
    for (int i = 0; i < array->m_length; i++) {
        if (array->m_data[i] == value) {
            return 1;
        }
    }

    return 0;
}

void printDynamicIntArray(struct DynamicIntArray* array)
{
    printf("{");
    for (int i = 0; i < array->m_length; i++)
    {
        printf("%d", array->m_data[i]);
        if (i < array->m_length - 1) {
            printf(",");
        }
    }
    printf("}\n");
}

// =====================================================================================
// =====================================================================================

static void exercise_DynamicIntArray_01()
{
    struct DynamicIntArray einFeld = { NULL, 0 };

    releaseDynamicIntArray(&einFeld);
}

static void exercise_DynamicIntArray_02()
{
    struct DynamicIntArray einFeld = { NULL, 0 };

    initDynamicIntArray(&einFeld, 10);

    printDynamicIntArray(&einFeld);

    releaseDynamicIntArray(&einFeld);
}


static void exercise_DynamicIntArray_03()
{
    struct DynamicIntArray dia = { 0, 0 };

    int values[] = { 1, 2, 3, 4, 5 };

    createDynamicIntArrayFromArray(&dia, values, 5);

    printDynamicIntArray(&dia);

    resizeDynamicIntArray(&dia, 10);

    printDynamicIntArray(&dia);

    releaseDynamicIntArray(&dia);

    printDynamicIntArray(&dia);
}

static void exercise_DynamicIntArray_04()
{
    int values[] = { -10, -5, 0, 5, 10 };

    struct DynamicIntArray dia = { 0, 0 };

    createDynamicIntArrayFromArray(&dia, values, 5);

    printDynamicIntArray(&dia);

    int min = minimum(&dia);
    printf("Minimum: %d\n", min);

    int max = maximum(&dia);
    printf("Maximum: %d\n", max);

    releaseDynamicIntArray(&dia);
}

static void exercise_DynamicIntArray_05()
{
    int values[] = { 10, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

    struct DynamicIntArray dia = { 0, 0 };

    createDynamicIntArrayFromArray(&dia, values, 10);

    printDynamicIntArray(&dia);

    int n = get(&dia, 5);
    printf("Value at index 5: %d\n", n);

    set(&dia, 5, 30);

    printDynamicIntArray(&dia);

    releaseDynamicIntArray(&dia);
}

static void exercise_DynamicIntArray_06()
{
    int values[] = { 10, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

    struct DynamicIntArray dia = { 0, 0 };

    createDynamicIntArrayFromArray(&dia, values, 10);

    printDynamicIntArray(&dia);

    // put into comments
    releaseDynamicIntArray(&dia);

    _CrtDumpMemoryLeaks();
}

static void exercise_DynamicIntArray_07()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    int values[] = { 10, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

    struct DynamicIntArray dia1 = { 0, 0 };

    createDynamicIntArrayFromArray(&dia1, values, 10);

    // ------------------------
    // Standard C: Hmm, da wird eine neue Struktur-Variable
    // mit dem Inhalt einer vorhandenen Struktur vorbelegt.

    // Das ist bei dynamischen Daten falsch - und eine Schwachstelle !
    // struct DynamicIntArray sa2 = sa1;

    // L�sung
    struct DynamicIntArray dia2;
    createDynamicIntArrayFromDynamicIntArray(&dia2, &dia1);

    printDynamicIntArray(&dia1);
    printDynamicIntArray(&dia2);

    releaseDynamicIntArray(&dia1);
    releaseDynamicIntArray(&dia2);

    _CrtDumpMemoryLeaks();
}

void exercise_dynamic_int_array()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    exercise_DynamicIntArray_01();
    exercise_DynamicIntArray_02();
    exercise_DynamicIntArray_03();
    exercise_DynamicIntArray_04();
    exercise_DynamicIntArray_05();
    exercise_DynamicIntArray_06();
    exercise_DynamicIntArray_07();
}

// =================================================================================
// ==========================================================================



// =====================================================================================
// End-of-File
// =====================================================================================
