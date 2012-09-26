#include <mruby.h>
#include <mruby/proc.h>
#include <mruby/data.h>
#include <mruby/compile.h>
#include <mrb_md5.h>

int
main() {
  mrb_state* mrb = mrb_open();
  mrb_md5_init(mrb);
  mrbc_context *c = mrbc_context_new(mrb);
  mrbc_filename(mrb, c, "-e");
  mrb_load_string_cxt(mrb, "puts MD5::md5_hex('お前はどこのワカメじゃ')", c);
  mrbc_context_free(mrb, c);
  return 0;
}
