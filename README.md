# ft\_printf

커스텀 printf 구현 과제

> 표준 C 함수 `printf()` 를 직접 구현한 프로젝트입니다. 42서울 과제이며, 다양한 형식 지정자와 플래그를 직접 처리하고 가변 인자를 사용하는 방법을 학습하는 데 목적이 있습니다.

---

## 📁 디렉토리 구조

```
ft_printf/
├── Makefile               # 빌드를 위한 메인 메이크파일
├── README.md              # 프로젝트 설명서
├── test.c                 # 간단한 테스트 코드
├── srcs/                  # 필수 파트 소스코드
│   ├── ft_printf.c        # 진입점 함수
│   ├── ft_printf.h        # 함수 및 플래그 구조체 정의
│   └── parse_*.c          # 형식별 처리 로직 (c, s, p, d, i, u, x, X, %)
├── bonus/                 # 보너스 플래그 지원 소스코드
│   ├── ft_printf_bonus.c  # 보너스용 printf 함수
│   ├── ft_printf_bonus.h  # 보너스 헤더
│   └── parse_*.c          # 보너스 플래그 포함 형식 처리
├── libft/                 # 자체 구현한 libft 함수 모음
│   ├── Makefile
│   └── ft_*.c             # 예: ft_itoa, ft_strlen 등
```

---

---

## ⚙️ 빌드 및 실행

```bash
make
./a.out  # 또는 테스트 파일에서 ft_printf 호출
```

보너스 기능 포함 빌드 시:

```bash
make bonus
```

---

## 🧪 테스트 예시

```c
ft_printf("%%d: %d\n", 42);         // 출력: %d: 42
ft_printf("%%x: %#x\n", 255);       // 출력: %x: 0xff
ft_printf("%%s: %10s\n", "test");  // 오른쪽 정렬된 문자열 출력
```

---

## 📚 과제 개요

* 사용 가능 함수: `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_end`
* 정적 라이브러리 `libftprintf.a` 생성
* 버퍼링 기능 구현은 불필요 (기존 libc printf와는 다름)
* `libtool`, `printf` 등 사용 금지

---
