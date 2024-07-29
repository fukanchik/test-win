#include <stdio.h>
#include <stdlib.h>

static char*
get_compression_path(const char *relpath)
{
    char pg_compression_path[8192];
    char szDir1[_MAX_DIR];
    char szDir[_MAX_DIR];
    errno_t rc;

    /* Not using 'drive' as relation_path is relative to $PGDATA */
    rc = _splitpath_s(relpath, NULL, 0, szDir1, _MAX_DIR, NULL, 0, NULL, 0);
    if (rc)
    return NULL;

    rc = _splitpath_s(szDir1, NULL, 0, szDir, _MAX_DIR, NULL, 0, NULL, 0);
    if (rc)
        return NULL;

    _snprintf(pg_compression_path, 8192, "%sxxx", szDir);

    return strdup(pg_compression_path);
}

int main()
{
  char *p = get_compression_path("a\\b\\c\\d");
  printf("%s\n", p);
  return 0;
}
