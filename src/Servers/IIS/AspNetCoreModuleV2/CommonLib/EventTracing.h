// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See License.txt in the project root for license information.

#pragma once

#include <httptrace.h>

#pragma warning( push )
#pragma warning ( disable : ALL_CODE_ANALYSIS_WARNINGS )

#include "aspnetcore_event.h"

#pragma warning( pop )

template< class EVENT, typename ...Params >
void RaiseEvent(IHttpTraceContext * pTraceContext,Params&&... params)
{
    if (pTraceContext != nullptr && EVENT::IsEnabled(pTraceContext))
    {
        EVENT::RaiseEvent(pTraceContext, std::forward<Params>(params)...);
    }
}

template< class EVENT, typename ...Params >
void RaiseEvent(IHttpContext * pHttpContext,Params&&... params)
{
    ::RaiseEvent<EVENT>(pHttpContext->GetTraceContext(), std::forward<Params>(params)...);
}
