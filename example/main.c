#include <mruby.h>
#include <mruby/proc.h>
#include <mruby/data.h>
#include <compile.h>
#include <mrb_md5.h>

#define _(...) #__VA_ARGS__ "\n"

int
main()
{
  int n;
  mrb_state* mrb;
  struct mrb_parser_state* st;
  char* code =
 _(
)_( require 'MD5'
)_( puts MD5::md5_hex('お前はどこのワカメじゃ')
);

  mrb = mrb_open();
  mrb_md5_init(mrb);
  st = mrb_parse_string(mrb, code);
  n = mrb_generate_code(mrb, st->tree);
  mrb_pool_close(st->pool);
  mrb_run(mrb, mrb_proc_new(mrb, mrb->irep[n]), mrb_nil_value());
  return 0;
}
