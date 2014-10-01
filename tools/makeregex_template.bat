#if _MSC_VER == 1500
#define VC_VERSION vc9
#elif _MSC_VER == 1400
#define VC_VERSION vc8
#elif _MSC_VER == 1800
#define VC_VERSION vc12
#endif

set CONFIG=%1
set BOOST_MAJOR=%2
set BOOST_MINOR=%3
set CPUBIT=%4
set BOOST_DIR=..\..\boost_%BOOST_MAJOR%_%BOOST_MINOR%
set REGEX_VC=VC_VERSION
set STAGE_DIR=%~dp0\..\proj\ext_lib%CPUBIT%\%CONFIG%

if "%CONFIG%" == "Debug" (
	set GD=gd
	set VARIANT=debug
) else (
	set GD=
	set VARIANT=release
)

set REGEX=libboost_regex-%REGEX_VC%0-mt-s%GD%-%BOOST_MAJOR%

pushd %BOOST_DIR%

b2 --build-dir=build/boost%CPUBIT% --stagedir=%STAGE_DIR% --with-regex address-model=%CPUBIT% variant=%VARIANT% link=static threading=multi runtime-link=static stage

popd

rem copy /Y %BOOST_DIR%\libs\regex\build\%REGEX_VC%0\%REGEX%.lib ..\proj\ext_lib%CPUBIT%\%CONFIG%\%REGEX%.lib
rem copy /Y %BOOST_DIR%\libs\regex\build\%REGEX_VC%0\%REGEX%.lib ..\proj\ext_lib%CPUBIT%\%CONFIG%\libboost_regex-mt-s%GD%-%BOOST_MAJOR%.lib

rem if "%CONFIG%" == "Debug" copy /Y %BOOST_DIR%\libs\regex\build\%REGEX_VC%0\%REGEX%.pdb ..\proj\ext_lib%CPUBIT%\%CONFIG%\%REGEX%.pdb
