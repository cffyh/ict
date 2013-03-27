/****************************************************************************
 *
 * Copyright (c) 2002~2005
 *     Software Research Lab.
 *     Institute of Computing Tech.
 *     Chinese Academy of Sciences
 *     All rights reserved.
 *
 * This file is the confidential and proprietary property of 
 * Institute of Computing Tech. and the posession or use of this file requires 
 * a written license from the author.
 * Filename: ICTCLAS.h
 * Abstract:
 *           interface for ICTCLAS(Institute of Computing Tech.,Chinese Lexical Analysis).
 * Author:   Kevin Zhang 
 * Email:    zhanghp@software.ict.ac.cn
 * Homepage: pipy_world.y365.com
 *
 * Date:     2002-8-2
 *
 * Notes:  1. All function will return true if success or false if failure
 *         2. Opearion failure maybe: 
 *            1) The data dir or data file missing
 *            2) Not invoke init() before any current operation
 *            3) Other: you could contact the author.
 ****************************************************************************/
#if !defined(__ICTCLAS_DLL_INCLUDED__)
#define __ICTCLAS_DLL_INCLUDED__

#define ICTCLAS_API  extern "C" __declspec(dllexport)//

ICTCLAS_API bool ICTCLAS_Init();
//Init the program and malloc memory
//The function must be invoked before any operation listed as following
ICTCLAS_API bool ICTCLAS_Exit();
//Exit the program and free memory
//The function must be invoked while you needn't any lexical anlysis
ICTCLAS_API bool ICTCLAS_SetOutputFormat(int nOutputFormat);
//Set output string format;default value is 0
//0:PKU criterion;
//i.e. ��/nr  ��ƽ/nr  ��/p  1978��/t  3��/t  9��/t  ����/v  ��/p  ����ʡ/ns  ������/ns  ��/w 
//1:973 criterion;
//i.e. ��\[nh]��ƽ\[nh]��\[p]1978��\[nt]3��\[nt]9��\[nt]����\[v]��\[p]����ʡ\[ns]������\[ns]��\[w]
//2: XML criterion;
//i.e. <any type="nh"><src>��</src></any><any type="nh"><src>��ƽ</src></any>
//     <any type="p"><src>��</src></any><any type="m"><src>1978</src></any>
//     <any type="q"><src>��</src></any><any type="nt"><src>3��</src></any>
//     <any type="nt"><src>9��</src></any><any type="v"><src>����</src></any>
//     <any type="p"><src>��</src></any><any type="ns"><src>����ʡ</src></any>
//     <any type="ns"><src>������</src></any><any type="w"><src>��</src></any>
ICTCLAS_API bool ICTCLAS_SetOperType(int nOperateType);
//Set operation Type; default value is 0
//0:Word Segmentation;
//i.e. ��  ��ƽ  ��  978  ��  3��  9��  ����  ��  ����ʡ  ������  ��  
//1:Word segmentation and tagging with upper POS
//i.e. ��/n  ��ƽ/n  ��/p  978/m  ��/q  3��/t  9��/t  ����/v  ��/p  ����ʡ/n  ������/n  ��/w  
//2:Word segmentation and tagging with total POS
//i.e. ��/nr  ��ƽ/nr  ��/p  1978��/t  3��/t  9��/t  ����/v  ��/p  ����ʡ/ns  ������/ns  ��/w 
ICTCLAS_API bool ICTCLAS_SentenceProcess(char *sSentence,unsigned int nResultCount,char **sResult);
//Process a sentence
//sSentence: the source sentence
//nResultCount: the count of result, the value cannot more than 10
//**sResult: the results buffer 
//i.e. �Ż�ƽ��1978��3��9�ճ����ڽ���ʡ�����ء�(nResultCount=5)
//Result 1(Score=-63.360033):��/nr  ��ƽ/nr  ��/p  1978��/t  3��/t  9��/t  ������/v  ����ʡ/ns  ������/ns  ��/w  
//Result 2(Score=-65.161371):��/nr  ��ƽ/nr  ��/p  1978��/t  3��/t  9��/t  ����/v  ��/p  ����ʡ/ns  ������/ns  ��/w  
//Result 3(Score=-73.205565):��/nr  ��ƽ/nr  ��/p  1978��/t  3��/t  9��/t  ����/v  ��/p  ����/ns  ʡ/n  ������/ns  ��/w  
//Result 4(Score=-80.693838):��/nr  ��ƽ/nr  ��/p  1978��/t  3��/t  9/m  �ճ�/v  ��/v  ��/p  ����ʡ/ns  ������/ns  ��/w  
//Result 5(Score=-82.372596):��/nr  ��ƽ/nr  ��/p  1978��/t  3��/t  9��/t  ����/v  ��/p  ����ʡ/ns  ��/n  ��/ag  ��/n  ��/w  

ICTCLAS_API bool ICTCLAS_ParagraphProcess(char *sParagraph,char *sResult);
//Process a paragraph
//sParagraph: The source paragraph 
//sResult: The result
//i.e. �Ż�ƽ��1978��3��9�ճ����ڽ���ʡ�����ء�(nResultCount=5)
//Result: ��/nr  ��ƽ/nr  ��/p  1978��/t  3��/t  9��/t  ������/v  ����ʡ/ns  ������/ns  ��/w  
ICTCLAS_API bool ICTCLAS_FileProcess(char *sSourceFilename,char *sResultFilename);
//Process a text file
//sSourceFilename: The source file name  
//sResultFilename: The result file name 
//i.e. FileProcess("E:\\Sample\\Corpus_NewPOS\\199802_Org.txt","E:\\Sample\\Corpus_NewPOS\\199802_Org_cla.txt");

#endif//#define __ICTCLAS_DLL_INCLUDED__