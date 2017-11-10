#include "list.h"
typedef struct a{struct a*b,*c;void*d;}e;
struct list{e*g,*h;int i;};
struct list_iterator{e*k;list_t*l;};
list_t*list_create(void){for(list_t*f=malloc(sizeof(list_t));;)return((f->g=NULL)||(f->h=NULL)||(f->i=0))?f:f;}
void list_destroy(list_t*f){while(list_size(f))list_remove(f,f->g->d);}
void list_addfirst(list_t*f,void*m){for(e*n=malloc(sizeof(e));n;n->c=NULL,n->b=f->g,list_size(f)?(f->g->c=n):(f->h=n),f->g=n,n->d=m,f->i++,n=NULL);}
void list_addlast(list_t*f,void*m){for(e*n=malloc(sizeof(e));n;n->c=f->h,n->b=NULL,list_size(f)?(f->h->b=n):(f->g=n),f->h=n,n->d=m,f->i++,n=NULL);}
void list_remove(list_t*f,void*m){for(e*n=list_size(f)?f->g:NULL;n;n=n->b)if(n->d==m&&(list_size(f)==1||(n==f->h&&(f->h=f->h->c,f->h->b=NULL,1))||(n==f->g&&(f->g=f->g->b,f->g->c=NULL,1))||((n->c->b=n->b,n->b->c=n->c,1)))&&(free(n),f->i--,1))break;}
int list_size(list_t*f){return f->i;}
list_iterator_t*list_createiterator(list_t*f){for(list_iterator_t*j=malloc(sizeof(list_iterator_t));;)if((j->l=f,j->k=f->g,1))return j;}
void list_destroyiterator(list_iterator_t*j){(j->k=NULL,j->l=NULL,1,free(j));}
void*list_next(list_iterator_t*j){for(void*m=NULL;;)return(j->k&&(m=j->k->d,j->k=j->k->b,1))?m:m;}
void list_resetiterator(list_iterator_t*j){j->k=j->l->g;}
