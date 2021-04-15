#ifndef CONFIG_H
#define CONFIG_H


struct mapper_t{
	char *prefix;
	char *root;
};


struct mapper_t *query_by_path(char *path);


#endif
