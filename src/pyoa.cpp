
/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"

#ifdef WIN32
#include <crtdbg.h>
#endif

extern "C" int Py_Main( int argc, char *argv[] );

extern "C" void initopenaccess();

//====================================================================
int main(int argc, char* argv[])
{
#ifdef WIN32
//    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetDbgFlag(0);
#endif
    PyImport_AppendInittab((char*)"openaccess", initopenaccess);

    try {
        // cdsInit(&argc,argv);
        cdsInitNonCDSApp("clsbd");
        oaDBInit(&argc, argv);

        Py_Main(argc,argv);
    }
    catch (oaException &excp) {
        printf("ERROR : %s\n",(const char*)(excp.getMsg()));
        exit(1);
    }
    exit(0);
    return 0;
}
