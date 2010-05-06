#import <Foundation/Foundation.h>
// Test case for radar 7468090

extern "C" int printf(const char *, ...);

class S {
public:
	S& operator = (const S& val) {
	  this->member = val.member;
	  this->member++;
	  return *this;
        }
	S (const S& val) {
	  this->member = val.member;
	  this->member++;
	}
	S () : member(10) {
	}
  int member;
};

@interface I : NSObject {
  S position;
}
@property(assign, nonatomic) S position;
- (void)finalize;

@end

@implementation I
@synthesize position;
- (void)finalize { [super finalize]; }
@end

int main() {
  I *i = [[I alloc] init];

  i.position.member = 100;

  printf("i.position.member = %d\n", i.position.member);

  S s1 = i.position;

  printf("i.position.member = %d\n", i.position.member);

  [i release];
  return 0;

}
