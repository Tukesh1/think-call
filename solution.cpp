 if (!(keyBegin < keyEnd))
            return;

        if (m_map.empty())
        {
            if (val == m_valBegin)
                return;

            m_map.insert(std::pair<K, V>(keyBegin, val));
            m_map.insert(std::pair<K, V>(keyEnd, m_valBegin));

            return;
        }

        auto itLowerBound = m_map.upper_bound(keyBegin);
        auto itLowerBoundExactSame = itLowerBound;
        if (itLowerBoundExactSame != m_map.begin())
        {
            itLowerBoundExactSame = std::prev(itLowerBoundExactSame);
            if (!(itLowerBoundExactSame->first < keyBegin))
                itLowerBound = itLowerBoundExactSame;
        }

        auto itHigherBound = m_map.upper_bound(keyEnd);

        if (itLowerBound == m_map.end() || itHigherBound == m_map.begin())
        {
            if (val == m_valBegin)
                return;

            m_map.insert(std::pair<K, V>(keyBegin, val));
            m_map.insert(std::pair<K, V>(keyEnd, m_valBegin));

            return;
        }

        auto itFindBeginValue = itLowerBound;

        V beginValue(m_valBegin);
        if (itFindBeginValue != m_map.begin())
            beginValue = std::prev(itFindBeginValue)->second;

        auto itFindEndValue = itHigherBound;

        V endValue(m_valBegin);
        if (itFindEndValue != m_map.end())
            endValue = std::prev(itFindEndValue)->second;

        if (itLowerBound != m_map.end() && itHigherBound != m_map.end())
        {
            if (std::distance(itLowerBound, itHigherBound) == 0)
            {
                if (val == beginValue)
                    return;

                m_map.insert(std::pair<K, V>(keyBegin, val));
                m_map.insert(std::pair<K, V>(keyEnd, beginValue));

                return;
            }
        }
        m_map.erase(itLowerBound, itHigherBound);

        if (m_map.empty())
        {
            if (val == m_valBegin)
                return;

            m_map.insert(std::pair<K, V>(keyBegin, val));
            m_map.insert(std::pair<K, V>(keyEnd, m_valBegin));

            return;
        }

        if (!(beginValue == val))
            m_map.insert(std::pair<K, V>(keyBegin, val));

        if (!(endValue == val))
            m_map.insert(std::pair<K, V>(keyEnd, endValue));

        return;
    
