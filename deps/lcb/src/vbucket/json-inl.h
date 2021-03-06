/**
 * Helper routines for cJSON
 */
/**
 * Utility function to retrieve a string from an object
 * @param parent Object
 * @param key Key for item
 * @param[out] value
 * @return nonzero on success, zero if not found, or not a string
 */
static int
get_jstr(cJSON *parent, const char *key, char **value)
{
    cJSON *res = cJSON_GetObjectItem(parent, key);
    if (res == NULL || res->type != cJSON_String) {
        *value = NULL;
        return 0;
    }

    *value = res->valuestring;
    return 1;
}

/**
 * Utility function to retrieve a sub-object from a parent object
 * @param parent
 * @param key
 * @param[out] value
 * @return nonzero on success, zero if not found or not an object
 */
static int
get_jobj(cJSON *parent, const char *key, cJSON **value)
{
    cJSON *res = cJSON_GetObjectItem(parent, key);
    if (res == NULL || res->type != cJSON_Object) {
        *value = NULL;
        return 0;
    }

    *value = res;
    return 1;
}

/**
 * Utility function to extract an integer from an object
 * @param parent
 * @param key
 * @param[out] value
 * @return nonzero on success, zero if not found or not a number
 */
static int
get_jint(cJSON *parent, const char *key, int *value)
{
    cJSON *res = cJSON_GetObjectItem(parent, key);
    if (res == NULL || res->type != cJSON_Number) {
        *value = 0;
        return 0;
    }

    *value = res->valueint;
    return 1;
}

/**
 * Convenience wrapper around get_jint() which writes its value to an unsigned
 * int.
 *
 * @param parent
 * @param key
 * @param value
 * @return
 */
static int
get_juint(cJSON *parent, const char *key, unsigned *value)
{
    int tmp = 0;
    if (!get_jint(parent, key, &tmp)) {
        *value = 0;
        return 0;
    }
    *value = tmp;
    return 1;
}

static int
get_jarray(cJSON *parent, const char *key, cJSON **value)
{
    cJSON *res = cJSON_GetObjectItem(parent, key);
    if (res == NULL || res->type != cJSON_Array) {
        *value = NULL;
        return 0;
    }
    *value = res;
    return 1;
}
